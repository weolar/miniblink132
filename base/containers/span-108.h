// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_CONTAINERS_SPAN_H_
#define BASE_CONTAINERS_SPAN_H_

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <algorithm>
#include <array>
#include <concepts>
#include <initializer_list>
#include <iosfwd>
#include <iterator>
#include <limits>
#include <memory>
#include <optional>
#include <ranges>
#include <span>
#include <type_traits>
#include <utility>

#include "base/check.h"
#include "base/compiler_specific.h"
#include "base/containers/checked_iterators.h"
#include "base/containers/contiguous_iterator.h"
#include "base/numerics/safe_conversions.h"
#include "base/types/to_address.h"

#undef max
#undef min

namespace base {

// [views.constants]
constexpr size_t dynamic_extent = std::numeric_limits<size_t>::max();

template <typename T, size_t Extent = dynamic_extent, typename InternalPtrType = T*> class span;

namespace internal {

template <size_t I> using size_constant = std::integral_constant<size_t, I>;

template <typename T> struct ExtentImpl : size_constant<dynamic_extent> { };

template <typename T, size_t N> struct ExtentImpl<T[N]> : size_constant<N> { };

template <typename T, size_t N> struct ExtentImpl<std::array<T, N>> : size_constant<N> { };

template <typename T, size_t N> struct ExtentImpl<base::span<T, N>> : size_constant<N> { };

template <typename T> using Extent = ExtentImpl<std::remove_cvref_t<T>>;

template <typename T> struct IsSpanImpl : std::false_type { };

template <typename T, size_t Extent> struct IsSpanImpl<span<T, Extent>> : std::true_type { };

template <typename T> using IsNotSpan = std::negation<IsSpanImpl<std::decay_t<T>>>;

template <typename T> struct IsStdArrayImpl : std::false_type { };

template <typename T, size_t N> struct IsStdArrayImpl<std::array<T, N>> : std::true_type { };

template <typename T> using IsNotStdArray = std::negation<IsStdArrayImpl<std::decay_t<T>>>;

template <typename T> using IsNotCArray = std::negation<std::is_array<std::remove_reference_t<T>>>;

template <typename From, typename To> using IsLegalDataConversion = std::is_convertible<From (*)[], To (*)[]>;

template <typename Iter, typename T> using IteratorHasConvertibleReferenceType = IsLegalDataConversion<std::remove_reference_t<std::iter_reference_t<Iter>>, T>;

template <typename Iter, typename T>
using EnableIfCompatibleContiguousIterator
    = std::enable_if_t<std::conjunction<IsContiguousIterator<Iter>, IteratorHasConvertibleReferenceType<Iter, T>>::value>;

template <typename Container, typename T>
using ContainerHasConvertibleData = IsLegalDataConversion<std::remove_pointer_t<decltype(std::data(std::declval<Container>()))>, T>;

template <typename Container> using ContainerHasIntegralSize = std::is_integral<decltype(std::size(std::declval<Container>()))>;

template <typename From, size_t FromExtent, typename To, size_t ToExtent>
using EnableIfLegalSpanConversion = std::enable_if_t<(ToExtent == dynamic_extent || ToExtent == FromExtent) && IsLegalDataConversion<From, To>::value>;

// SFINAE check if Array can be converted to a span<T>.
template <typename Array, typename T, size_t Extent>
using EnableIfSpanCompatibleArray
    = std::enable_if_t<(Extent == dynamic_extent || Extent == internal::Extent<Array>::value) && ContainerHasConvertibleData<Array, T>::value>;

// SFINAE check if Container can be converted to a span<T>.
template <typename Container, typename T>
using IsSpanCompatibleContainer = std::conjunction<IsNotSpan<Container>, IsNotStdArray<Container>, IsNotCArray<Container>,
    ContainerHasConvertibleData<Container, T>, ContainerHasIntegralSize<Container>>;

template <typename Container, typename T> using EnableIfSpanCompatibleContainer = std::enable_if_t<IsSpanCompatibleContainer<Container, T>::value>;

template <typename Container, typename T, size_t Extent>
using EnableIfSpanCompatibleContainerAndSpanIsDynamic = std::enable_if_t<IsSpanCompatibleContainer<Container, T>::value && Extent == dynamic_extent>;

// A helper template for storing the size of a span. Spans with static extents
// don't require additional storage, since the extent itself is specified in the
// template parameter.
template <size_t Extent> class ExtentStorage {
public:
    constexpr explicit ExtentStorage(size_t size) noexcept
    {
    }
    constexpr size_t size() const noexcept
    {
        return Extent;
    }
};

// Specialization of ExtentStorage for dynamic extents, which do require
// explicit storage for the size.
template <> struct ExtentStorage<dynamic_extent> {
    constexpr explicit ExtentStorage(size_t size) noexcept
        : size_(size)
    {
    }
    constexpr size_t size() const noexcept
    {
        return size_;
    }

private:
    size_t size_;
};

// must_not_be_dynamic_extent prevents |dynamic_extent| from being returned in a
// constexpr context.
template <size_t kExtent> constexpr size_t must_not_be_dynamic_extent()
{
    static_assert(kExtent != dynamic_extent, "EXTENT should only be used for containers with a static extent.");
    return kExtent;
}

} // namespace internal

// A span is a value type that represents an array of elements of type T. Since
// it only consists of a pointer to memory with an associated size, it is very
// light-weight. It is cheap to construct, copy, move and use spans, so that
// users are encouraged to use it as a pass-by-value parameter. A span does not
// own the underlying memory, so care must be taken to ensure that a span does
// not outlive the backing store.
//
// span is somewhat analogous to StringPiece, but with arbitrary element types,
// allowing mutation if T is non-const.
//
// span is implicitly convertible from C++ arrays, as well as most [1]
// container-like types that provide a data() and size() method (such as
// std::vector<T>). A mutable span<T> can also be implicitly converted to an
// immutable span<const T>.
//
// Consider using a span for functions that take a data pointer and size
// parameter: it allows the function to still act on an array-like type, while
// allowing the caller code to be a bit more concise.
//
// For read-only data access pass a span<const T>: the caller can supply either
// a span<const T> or a span<T>, while the callee will have a read-only view.
// For read-write access a mutable span<T> is required.
//
// Without span:
//   Read-Only:
//     // std::string HexEncode(const uint8_t* data, size_t size);
//     std::vector<uint8_t> data_buffer = GenerateData();
//     std::string r = HexEncode(data_buffer.data(), data_buffer.size());
//
//  Mutable:
//     // ssize_t SafeSNPrintf(char* buf, size_t N, const char* fmt, Args...);
//     char str_buffer[100];
//     SafeSNPrintf(str_buffer, sizeof(str_buffer), "Pi ~= %lf", 3.14);
//
// With span:
//   Read-Only:
//     // std::string HexEncode(base::span<const uint8_t> data);
//     std::vector<uint8_t> data_buffer = GenerateData();
//     std::string r = HexEncode(data_buffer);
//
//  Mutable:
//     // ssize_t SafeSNPrintf(base::span<char>, const char* fmt, Args...);
//     char str_buffer[100];
//     SafeSNPrintf(str_buffer, "Pi ~= %lf", 3.14);
//
// Spans with "const" and pointers
// -------------------------------
//
// Const and pointers can get confusing. Here are vectors of pointers and their
// corresponding spans:
//
//   const std::vector<int*>        =>  base::span<int* const>
//   std::vector<const int*>        =>  base::span<const int*>
//   const std::vector<const int*>  =>  base::span<const int* const>
//
// Differences from the C++20 draft
// --------------------------------
//
// http://eel.is/c++draft/views contains the latest C++20 draft of std::span.
// Chromium tries to follow the draft as close as possible. Differences between
// the draft and the implementation are documented in subsections below.
//
// Differences from [span.objectrep]:
// - as_bytes() and as_writable_bytes() return spans of uint8_t instead of
//   std::byte (std::byte is a C++17 feature)
//
// Differences from [span.cons]:
// - Constructing a static span (i.e. Extent != dynamic_extent) from a dynamic
//   sized container (e.g. std::vector) requires an explicit conversion (in the
//   C++20 draft this is simply UB)
//
// Furthermore, all constructors and methods are marked noexcept due to the lack
// of exceptions in Chromium.
//
// Due to the lack of class template argument deduction guides in C++14
// appropriate make_span() utility functions are provided.

// [span], class template span
template <typename T, size_t Extent, typename InternalPtrType> class GSL_POINTER span : public internal::ExtentStorage<Extent> {
private:
    using ExtentStorage = internal::ExtentStorage<Extent>;

public:
    using element_type = T;
    using value_type = std::remove_cv_t<T>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    using iterator = CheckedContiguousIterator<T>;
    // TODO(https://crbug.com/828324): Drop the const_iterator typedef once gMock
    // supports containers without this nested type.
    using const_iterator = iterator;
    using reverse_iterator = std::reverse_iterator<iterator>;
    static constexpr size_t extent = Extent;

    // [span.cons], span constructors, copy, assignment, and destructor
    constexpr span() noexcept
        : ExtentStorage(0)
        , data_(nullptr)
    {
        static_assert(Extent == dynamic_extent || Extent == 0, "Invalid Extent");
    }

    template <typename It, typename = internal::EnableIfCompatibleContiguousIterator<It, T>>
    constexpr span(It first, size_t count) noexcept
        : ExtentStorage(count)
        ,
        // The use of to_address() here is to handle the case where the iterator
        // `first` is pointing to the container's `end()`. In that case we can
        // not use the address returned from the iterator, or dereference it
        // through the iterator's `operator*`, but we can store it. We must assume
        // in this case that `count` is 0, since the iterator does not point to
        // valid data. Future hardening of iterators may disallow pulling the
        // address from `end()`, as demonstrated by asserts() in libstdc++:
        // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93960.
        //
        // The span API dictates that the `data()` is accessible when size is 0,
        // since the pointer may be valid, so we cannot prevent storing and
        // giving out an invalid pointer here without breaking API compatibility
        // and our unit tests. Thus protecting against this can likely only be
        // successful from inside iterators themselves, where the context about
        // the pointer is known.
        //
        // We can not protect here generally against an invalid iterator/count
        // being passed in, since we have no context to determine if the
        // iterator or count are valid.
        data_(base::to_address(first))
    {
        CHECK(Extent == dynamic_extent || Extent == count);
    }

    template <typename It, typename End, typename = internal::EnableIfCompatibleContiguousIterator<It, T>,
        typename = std::enable_if_t<!std::is_convertible<End, size_t>::value>>
    constexpr span(It begin, End end) noexcept
        // Subtracting two iterators gives a ptrdiff_t, but the result should be
        // non-negative: see CHECK below.
        : span(begin, static_cast<size_t>(end - begin))
    {
        // Note: CHECK_LE is not constexpr, hence regular CHECK must be used.
        CHECK(begin <= end);
    }

    template <size_t N, typename = internal::EnableIfSpanCompatibleArray<T (&)[N], T, Extent>>
    constexpr span(T (&array)[N]) noexcept
        : span(std::data(array), N)
    {
    }

    template <typename U, size_t N, typename = internal::EnableIfSpanCompatibleArray<std::array<U, N>&, T, Extent>>
    constexpr span(std::array<U, N>& array) noexcept
        : span(std::data(array), N)
    {
    }

    template <typename U, size_t N, typename = internal::EnableIfSpanCompatibleArray<const std::array<U, N>&, T, Extent>>
    constexpr span(const std::array<U, N>& array) noexcept
        : span(std::data(array), N)
    {
    }

    template <typename U, size_t N, typename = internal::EnableIfSpanCompatibleArray<const std::array<U, N>&, T, Extent>>
    constexpr span(const std::string& str) noexcept
        : span(std::data(str), N)
    {
    }

    // Conversion from a container that has compatible std::data() and integral
    // std::size().
    template <typename Container, typename = internal::EnableIfSpanCompatibleContainerAndSpanIsDynamic<Container&, T, Extent>>
    constexpr span(Container& container) noexcept
        : span(std::data(container), std::size(container))
    {
    }

    template <typename Container, typename = internal::EnableIfSpanCompatibleContainerAndSpanIsDynamic<const Container&, T, Extent>>
    constexpr span(const Container& container) noexcept
        : span(std::data(container), std::size(container))
    {
    }

    constexpr span(const span& other) noexcept = default;

    // Conversions from spans of compatible types and extents: this allows a
    // span<T> to be seamlessly used as a span<const T>, but not the other way
    // around. If extent is not dynamic, OtherExtent has to be equal to Extent.
    template <typename U, size_t OtherExtent, typename = internal::EnableIfLegalSpanConversion<U, OtherExtent, T, Extent>>
    constexpr span(const span<U, OtherExtent>& other)
        : span(other.data(), other.size())
    {
    }

    constexpr span& operator=(const span& other) noexcept = default;
    ~span() noexcept = default;

    // [span.sub], span subviews
    template <size_t Count> constexpr span<T, Count> first() const noexcept
    {
        static_assert(Count <= Extent, "Count must not exceed Extent");
        CHECK(Extent != dynamic_extent || Count <= size());
        return { data(), Count };
    }

    template <size_t Count> constexpr span<T, Count> last() const noexcept
    {
        static_assert(Count <= Extent, "Count must not exceed Extent");
        CHECK(Extent != dynamic_extent || Count <= size());
        return { data() + (size() - Count), Count };
    }

    template <size_t Offset, size_t Count = dynamic_extent>
    constexpr span<T, (Count != dynamic_extent ? Count : (Extent != dynamic_extent ? Extent - Offset : dynamic_extent))> subspan() const noexcept
    {
        static_assert(Offset <= Extent, "Offset must not exceed Extent");
        static_assert(Count == dynamic_extent || Count <= Extent - Offset, "Count must not exceed Extent - Offset");
        CHECK(Extent != dynamic_extent || Offset <= size());
        CHECK(Extent != dynamic_extent || Count == dynamic_extent || Count <= size() - Offset);
        return { data() + Offset, Count != dynamic_extent ? Count : size() - Offset };
    }

    constexpr span<T, dynamic_extent> first(size_t count) const noexcept
    {
        // Note: CHECK_LE is not constexpr, hence regular CHECK must be used.
        CHECK(count <= size());
        return { data(), count };
    }

    constexpr span<T, dynamic_extent> last(size_t count) const noexcept
    {
        // Note: CHECK_LE is not constexpr, hence regular CHECK must be used.
        CHECK(count <= size());
        return { data() + (size() - count), count };
    }

    constexpr span<T, dynamic_extent> subspan(size_t offset, size_t count = dynamic_extent) const noexcept
    {
        // Note: CHECK_LE is not constexpr, hence regular CHECK must be used.
        CHECK(offset <= size());
        CHECK(count == dynamic_extent || count <= size() - offset);
        return { data() + offset, count != dynamic_extent ? count : size() - offset };
    }

    // [span.obs], span observers
    constexpr size_t size() const noexcept
    {
        return ExtentStorage::size();
    }
    constexpr size_t size_bytes() const noexcept
    {
        return size() * sizeof(T);
    }
    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return size() == 0;
    }

    // [span.elem], span element access
    constexpr T& operator[](size_t idx) const noexcept
    {
        // Note: CHECK_LT is not constexpr, hence regular CHECK must be used.
        CHECK(idx < size());
        return *(data() + idx);
    }

    constexpr T& front() const noexcept
    {
        static_assert(Extent == dynamic_extent || Extent > 0, "Extent must not be 0");
        CHECK(Extent != dynamic_extent || !empty());
        return *data();
    }

    constexpr T& back() const noexcept
    {
        static_assert(Extent == dynamic_extent || Extent > 0, "Extent must not be 0");
        CHECK(Extent != dynamic_extent || !empty());
        return *(data() + size() - 1);
    }

    constexpr T* data() const noexcept
    {
        return data_;
    }

    // [span.iter], span iterator support
    constexpr iterator begin() const noexcept
    {
        return iterator(data_, data_ + size());
    }

    constexpr iterator end() const noexcept
    {
        return iterator(data_, data_ + size(), data_ + size());
    }

    constexpr reverse_iterator rbegin() const noexcept
    {
        return reverse_iterator(end());
    }

    constexpr reverse_iterator rend() const noexcept
    {
        return reverse_iterator(begin());
    }

private:
    T* data_;
};

// span<T, Extent>::extent can not be declared inline prior to C++17, hence this
// definition is required.
#if 0
template <class T, size_t Extent> constexpr size_t span<T, Extent, T*>::extent;
#endif

//--
// [span], class template span
template <typename T, typename InternalPtrType> class GSL_POINTER span<T, dynamic_extent, InternalPtrType> {
public:
    using element_type = T;
    using value_type = std::remove_cv_t<T>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using iterator = CheckedContiguousIterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    static constexpr size_t extent = dynamic_extent;

    constexpr span() noexcept = default;

    // Constructs a span from a contiguous iterator and a size.
    //
    // # Safety
    // The iterator must point to the first of at least `count` many elements, or
    // Undefined Behaviour can result as the span will allow access beyond the
    // valid range of the collection pointed to by the iterator.
    template <typename It>
#if 0
    requires(internal::CompatibleIter<T, It>)
#endif
    UNSAFE_BUFFER_USAGE constexpr span(It first, StrictNumeric<size_t> count)
        // The use of to_address() here is to handle the case where the iterator
        // `first` is pointing to the container's `end()`. In that case we can
        // not use the address returned from the iterator, or dereference it
        // through the iterator's `operator*`, but we can store it. We must
        // assume in this case that `count` is 0, since the iterator does not
        // point to valid data. Future hardening of iterators may disallow
        // pulling the address from `end()`, as demonstrated by asserts() in
        // libstdc++: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93960.
        //
        // The span API dictates that the `data()` is accessible when size is 0,
        // since the pointer may be valid, so we cannot prevent storing and
        // giving out an invalid pointer here without breaking API compatibility
        // and our unit tests. Thus protecting against this can likely only be
        // successful from inside iterators themselves, where the context about
        // the pointer is known.
        //
        // We can not protect here generally against an invalid iterator/count
        // being passed in, since we have no context to determine if the
        // iterator or count are valid.
        : data_(base::to_address(first))
        , size_(count)
    {
        // `count != 0` implies non-null `data_`.  Consider using
        // `base::SpanOrSize<T>` to represent a size that may or may not be
        // accompanied by the actual data.
        DCHECK(count == 0 || !!data_);
    }

    // Constructs a span from a contiguous iterator and a size.
    //
    // # Safety
    // The begin and end iterators must be for the same allocation, and `begin <=
    // end` or Undefined Behaviour can result as the span will allow access beyond
    // the valid range of the collection pointed to by `begin`.
    template <typename It, typename End>
#if 0
    requires(internal::CompatibleIter<T, It>&& std::sized_sentinel_for<End, It> && !std::is_convertible_v<End, size_t>)
#endif
    UNSAFE_BUFFER_USAGE constexpr span(It begin, End end)
        // SAFETY: The caller must guarantee that the iterator and end sentinel
        // are part of the same allocation, in which case it is the number of
        // elements between the iterators and thus a valid size for the pointer to
        // the element at `begin`.
        //
        // We CHECK that `end - begin` did not underflow below. Normally checking
        // correctness afterward is flawed, however underflow is not UB and the
        // size is not converted to an invalid pointer (which would be UB) before
        // we CHECK for underflow.
        : UNSAFE_BUFFERS(span(begin, static_cast<size_t>(end - begin)))
    {
        // Verify `end - begin` did not underflow.
        CHECK(begin <= end);
    }

    template <size_t N>
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr span(std::type_identity_t<T> (&arr LIFETIME_BOUND)[N]) noexcept
        // SAFETY: The type signature guarantees `arr` contains `N` elements.
        : UNSAFE_BUFFERS(span(arr, N))
    {
    }

    //   template <typename R>
    //     requires(internal::CompatibleRange<T, R>)
    //   // NOLINTNEXTLINE(google-explicit-constructor)
    //   constexpr span(R&& range LIFETIME_BOUND)
    //       // SAFETY: `std::ranges::size()` returns the number of elements
    //       // `std::ranges::data()` will point to, so accessing those elements will
    //       // be safe.
    //       : UNSAFE_BUFFERS(span(std::ranges::data(range), std::ranges::size(range))) {}
    //
    //   template <typename R>
    //     requires(internal::CompatibleRange<T, R> && std::ranges::borrowed_range<R>)
    //   // NOLINTNEXTLINE(google-explicit-constructor)
    //   constexpr span(R&& range)
    //       // SAFETY: `std::ranges::size()` returns the number of elements
    //       // `std::ranges::data()` will point to, so accessing those elements will
    //       // be safe.
    //       : UNSAFE_BUFFERS(span(std::ranges::data(range), std::ranges::size(range))) {}

    constexpr span(std::initializer_list<value_type> il LIFETIME_BOUND)
#if 0
    requires(std::is_const_v<T>)
#endif
        // SAFETY: `size()` is exactly the number of elements in the initializer
        // list, so accessing that many will be safe.
        : UNSAFE_BUFFERS(span(il.begin(), il.size()))
    {
    }

    constexpr span(const span& other) noexcept = default;

    template <typename OtherT, size_t OtherN, typename OtherInternalPtrType>
#if 0
    requires(internal::LegalDataConversion<OtherT, T>)
#endif
    // NOLINTNEXTLINE(google-explicit-constructor)
    constexpr span(const span<OtherT, OtherN, OtherInternalPtrType>& s) noexcept
        : data_(s.data())
        , size_(s.size())
    {
    }

    constexpr span& operator=(const span& other) noexcept = default;

    // [span.sub], span subviews
    template <size_t Count> constexpr span<T, Count> first() const noexcept
    {
        CHECK_LE(Count, size());
        // SAFETY: span provides that data() points to at least `size()` many
        // elements. `Count` is non-negative by its type and `Count <= size()` from
        // the CHECK above. So `Count` is a valid new size for `data()`.
        return UNSAFE_BUFFERS(span<T, Count>(data(), Count));
    }

    template <size_t Count> constexpr span<T, Count> last() const noexcept
    {
        CHECK_LE(Count, size());
        // SAFETY: span provides that data() points to at least `size()` many
        // elements. `Count` is non-negative by its type and `Count <= size()` from
        // the check above. So `0 <= size() - Count <= size()`, meaning
        // `size() - Count` is a valid new size for `data()` and it will point to
        // `Count` many elements.
        return UNSAFE_BUFFERS(span<T, Count>(data() + (size() - Count), Count));
    }

    // Returns a span over the first `count` elements.
    //
    // # Checks
    // The function CHECKs that the span contains at least `count` elements and
    // will terminate otherwise.
    constexpr span<T> first(StrictNumeric<size_t> count) const noexcept
    {
        CHECK_LE(size_t { count }, size());
        // SAFETY: span provides that data() points to at least `size()` many
        // elements. `count` is non-negative by its type and `count <= size()` from
        // the CHECK above. So `count` is a valid new size for `data()`.
        return UNSAFE_BUFFERS(span<T>(data(), count));
    }

    // Returns a span over the last `count` elements.
    //
    // # Checks
    // The function CHECKs that the span contains at least `count` elements and
    // will terminate otherwise.
    constexpr span<T> last(StrictNumeric<size_t> count) const noexcept
    {
        CHECK_LE(size_t { count }, size());
        // SAFETY: span provides that data() points to at least `size()` many
        // elements. `count` is non-negative by its type and `count <= size()` from
        // the CHECK above. So `0 <= size() - count <= size()`, meaning
        // `size() - count` is a valid new size for `data()` and it will point to
        // `count` many elements.
        return UNSAFE_BUFFERS(span<T>(data() + (size() - size_t { count }), count));
    }

    template <size_t Offset, size_t Count = dynamic_extent> constexpr span<T, Count> subspan() const noexcept
    {
        CHECK_LE(Offset, size());
        CHECK(Count == dynamic_extent || Count <= size() - Offset);
        const size_t new_extent = Count != dynamic_extent ? Count : size() - Offset;
        // SAFETY: span provides that data() points to at least `size()` many
        // elements.
        //
        // If Count is dynamic_extent, `new_extent` becomes `size() - Offset`. Since
        // `Offset <= size()` from the check above, then `Offset` is a valid offset
        // for data(), and `Offset + new_extent = Offset + size() - Offset = size()
        // >= Offset` is also a valid offset that is not before `Offset`. This makes
        // a span at `Offset` with size `new_extent` valid.
        //
        // Otherwise `Count <= size() - Offset` and `0 <= Offset <= size()` by the
        // check above, so `Offset <= size() - Count` and `size() - Count` can not
        // underflow. Then `Offset` is a valid offset for data() and `new_extent` is
        // `Count <= size() - Offset`, so `Offset + extent <= Offset + size() -
        // Offset = size()` which makes both `Offset` and `Offset + new_extent`
        // valid offsets for data(), and since `new_extent` is non-negative, `Offset
        // + new_extent` is not before `Offset` so `new_extent` is a valid size for
        // the span at `data() + Offset`.
        return UNSAFE_BUFFERS(span<T, Count>(data() + Offset, new_extent));
    }

    // Returns a span over the first `count` elements starting at the given
    // `offset` from the start of the span.
    //
    // # Checks
    // The function CHECKs that the span contains at least `offset + count`
    // elements, or at least `offset` elements if `count` is not specified, and
    // will terminate otherwise.
    constexpr span<T> subspan(size_t offset, size_t count = dynamic_extent) const noexcept
    {
        CHECK_LE(offset, size());
        CHECK(count == dynamic_extent || count <= size() - offset) << " count: " << count << " offset: " << offset << " size: " << size();
        const size_t new_extent = count != dynamic_extent ? count : size() - offset;
        // SAFETY: span provides that data() points to at least `size()` many
        // elements.
        //
        // If count is dynamic_extent, `new_extent` becomes `size() - offset`. Since
        // `offset <= size()` from the check above, then `offset` is a valid offset
        // for data(), and `offset + new_extent = offset + size() - offset = size()
        // >= offset` is also a valid offset that is not before `offset`. This makes
        // a span at `offset` with size `new_extent` valid.
        //
        // Otherwise `count <= size() - offset` and `0 <= offset <= size()` by the
        // checks above, so `offset <= size() - count` and `size() - count` can not
        // underflow. Then `offset` is a valid offset for data() and `new_extent` is
        // `count <= size() - offset`, so `offset + new_extent <= offset + size() -
        // offset = size()` which makes both `offset` and `offset + new_extent`
        // valid offsets for data(), and since `new_extent` is non-negative, `offset
        // + new_extent` is not before `offset` so `new_extent` is a valid size for
        // the span at `data() + offset`.
        return UNSAFE_BUFFERS(span<T>(data() + offset, new_extent));
    }

    // Convert a dynamic-extent span to a fixed-extent span. Returns a
    // `span<T, Extent>` iff `size() == Extent`; otherwise, returns
    // `std::nullopt`.
    template <size_t Extent> constexpr std::optional<span<T, Extent>> to_fixed_extent() const
    {
        return size() == Extent ? std::optional(span<T, Extent>(*this)) : std::nullopt;
    }

    // Splits a span into two at the given `offset`, returning two spans that
    // cover the full range of the original span.
    //
    // Similar to calling subspan() with the `offset` as the length on the first
    // call, and then the `offset` as the offset in the second.
    //
    // The split_at<N>() overload allows construction of a fixed-size span from a
    // compile-time constant. If the input span is fixed-size, both output output
    // spans will be. Otherwise, the first will be fixed-size and the second will
    // be dynamic-size.
    //
    // This is a non-std extension that  is inspired by the Rust slice::split_at()
    // and split_at_mut() methods.
    //
    // # Checks
    // The function CHECKs that the span contains at least `offset` elements and
    // will terminate otherwise.
    constexpr std::pair<span<T>, span<T>> split_at(size_t offset) const noexcept
    {
        return { first(offset), subspan(offset) };
    }

    // An overload of `split_at` which returns a fixed-size span.
    //
    // # Checks
    // The function CHECKs that the span contains at least `Offset` elements and
    // will terminate otherwise.
    template <size_t Offset> constexpr std::pair<span<T, Offset>, span<T>> split_at() const noexcept
    {
        CHECK_LE(Offset, size());
        return { first<Offset>(), subspan(Offset) };
    }

    // [span.obs], span observers
    constexpr size_t size() const noexcept
    {
        return size_;
    }
    constexpr size_t size_bytes() const noexcept
    {
        return size() * sizeof(T);
    }
    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return size() == 0;
    }

    // [span.elem], span element access
    //
    // # Checks
    // The function CHECKs that the `idx` is inside the span and will terminate
    // otherwise.
    constexpr T& operator[](size_t idx) const noexcept
    {
        CHECK_LT(idx, size());
        // SAFETY: Since data() always points to at least `size()` elements, the
        // check above ensures `idx < size()` and is thus in range for data().
        return UNSAFE_BUFFERS(data()[idx]);
    }

    // Returns a pointer to an element in the span.
    //
    // This avoids the construction of a reference to the element, which is
    // important for cases such as in-place new, where the memory is
    // uninitialized.
    //
    // This is sugar for `span.subspan(idx, 1u).data()` which also ensures the
    // returned span has a pointer into and not past the end of the original span.
    //
    // # Checks
    // The function CHECKs that the `idx` is inside the span and will terminate
    // otherwise.
    constexpr T* get_at(size_t idx) const noexcept
    {
        CHECK_LT(idx, size());
        // SAFETY: Since data() always points to at least `N` elements, the check
        // above ensures `idx < N` and is thus in range for data().
        return UNSAFE_BUFFERS(data() + idx);
    }

    // Returns a reference to the first element in the span.
    //
    // # Checks
    // The function CHECKs that the span is not empty and will terminate
    // otherwise.
    constexpr T& front() const noexcept
    {
        CHECK(!empty());
        // SAFETY: Since data() always points to at least `size()` elements, the
        // check above above ensures `0 < size()` and is thus in range for data().
        return UNSAFE_BUFFERS(data()[0]);
    }

    // Returns a reference to the last element in the span.
    //
    // # Checks
    // The function CHECKs that the span is not empty and will terminate
    // otherwise.
    constexpr T& back() const noexcept
    {
        CHECK(!empty());
        // SAFETY: Since data() always points to at least `size()` elements, the
        // check above above ensures `size() > 0` and thus `size() - 1` does not
        // underflow and is in range for data().
        return UNSAFE_BUFFERS(data()[size() - 1]);
    }

    // Returns a pointer to the first element in the span. If the span is empty
    // (`size()` is 0), the returned pointer may or may not be null, and it must
    // not be dereferenced.
    //
    // It is always valid to add `size()` to the the pointer in C++ code, though
    // it may be invalid in C code when the span is empty.
    constexpr T* data() const noexcept
    {
        return data_;
    }

    // [span.iter], span iterator support
    constexpr iterator begin() const noexcept
    {
        // SAFETY: span provides that data() points to at least `size()` many
        // elements, and size() is non-negative. So data() + size() is a valid
        // pointer for the data() allocation.
        return UNSAFE_BUFFERS(iterator(data(), data() + size()));
    }

    constexpr iterator end() const noexcept
    {
        // SAFETY: span provides that data() points to at least `size()` many
        // elements, and size() is non-negative. So data() + size() is a valid
        // pointer for the data() allocation.
        return UNSAFE_BUFFERS(iterator(data(), data() + size(), data() + size()));
    }

    constexpr reverse_iterator rbegin() const noexcept
    {
        return reverse_iterator(end());
    }

    constexpr reverse_iterator rend() const noexcept
    {
        return reverse_iterator(begin());
    }

    // Bounds-checked copy from a span. The spans must be the exact same size or a
    // hard CHECK() occurs. The spans are allowed to overlap.
    //
    // This is a non-std extension that is inspired by the Rust
    // slice::copy_from_slice() method.
    //
    // If it's known the spans can not overlap, `copy_from_nonoverlapping()`
    // provides an unsafe alternative that avoids intermediate copies.
    //
    // # Checks
    // The function CHECKs that the `other` span has the same size as itself and
    // will terminate otherwise.
    constexpr void copy_from(span<const T> other)
    //requires(!std::is_const_v<T>)
    {
        CHECK_EQ(size(), other.size());

        if constexpr (std::is_trivially_copyable_v<T>) {
            if (!empty()) {
                // Avoid having to look for overlap and pick a direction, memmove allows
                // arbitrary overlap.
                memmove(data(), other.data(), size_bytes());
            }
        } else {
            // Use intptrs as pointers from different allocations are not comparable.
            const auto data_intptr = reinterpret_cast<uintptr_t>(data());
            const auto other_data_intptr = reinterpret_cast<uintptr_t>(other.data());
            if (data_intptr < other_data_intptr) {
                // SAFETY: The std::copy() here does not check bounds, but we have
                // verified that `this` and `other` have the same bounds above (and are
                // pointers of the same type), so `data()` and `other.data()` both have
                // at least `size()` elements.
                UNSAFE_BUFFERS(std::copy(other.data(), other.data() + size(), data()));
            } else if (data_intptr != other_data_intptr) {
                // SAFETY: The std::copy() here does not check bounds, but we have
                // verified that `this` and `other` have the same bounds above (and are
                // pointers of the same type), so `data()` and `other.data()` both have
                // at least `size()` elements.
                UNSAFE_BUFFERS(std::copy_backward(other.data(), other.data() + size(), data() + size()));
            }
        }
    }

    // Bounds-checked copy from a non-overlapping span. The spans must be the
    // exact same size or a hard CHECK() occurs.
    //
    // This is a non-std extension that is inspired by the Rust
    // slice::copy_from_slice() method.
    //
    // # Checks
    // The function CHECKs that the `other` span has the same size as itself and
    // will terminate otherwise.
    //
    // # Safety
    // The `other` span must not overlap with `this` or Undefined Behaviour may
    // occur. Hence this must be called from inside an UNSAFE_BUFFERS() region
    // and there must be a // SAFETY: comment explaining why the buffers are
    // known not to overlap.
    //
    // If the calling code is not performance sensitive, the safer copy_from()
    // method may be a simpler option.
    UNSAFE_BUFFER_USAGE constexpr void copy_from_nonoverlapping(span<const T> other)
    //requires(!std::is_const_v<T>)
    {
        CHECK_EQ(size(), other.size());
        // Verify non-overlapping in developer builds. Use intptrs as pointers from
        // different allocations are not comparable.
        const auto data_intptr = reinterpret_cast<uintptr_t>(data());
        const auto other_data_intptr = reinterpret_cast<uintptr_t>(other.data());
        DCHECK(data_intptr + size_bytes() <= other_data_intptr || data_intptr >= other_data_intptr + size_bytes());
        // When compiling with -Oz, std::ranges::copy() does not get inlined, which
        // makes copy_from() very expensive compared to memcpy for small sizes (up
        // to around 4x slower). We observe that this is because ranges::copy() uses
        // begin()/end() and span's iterators are checked iterators, not just
        // pointers. This additional complexity prevents inlining and breaks the
        // ability for the compiler to eliminate code.
        //
        // See also https://crbug.com/1396134.
        //
        // We also see std::copy() (with pointer arguments! not iterators) optimize
        // and inline better than memcpy() since memcpy() needs to rely on
        // size_bytes(), which while computable at compile time when `other` has a
        // fixed size, the optimizer stumbles on with -Oz.
        //
        // SAFETY: The std::copy() here does not check bounds, but we have verified
        // that `this` and `other` have the same bounds above (and are pointers of
        // the same type), so `data()` and `other.data()` both have at least
        // `size()` elements.
        UNSAFE_BUFFERS(std::copy(other.data(), other.data() + size(), data()));
    }

    // Bounds-checked copy from a span into the front of this span. The `other`
    // span must not be larger than this span.
    //
    // Prefer copy_from() when you expect the entire span to be written to. This
    // method does not make that guarantee and may leave some bytes uninitialized
    // in the destination span, while `copy_from()` ensures the entire span is
    // written which helps prevent bugs.
    //
    // This is sugar for `span.first(other.size()).copy_from(other)` to avoid the
    // need for writing the size twice, while also preserving compile-time size
    // information.
    //
    // # Checks
    // If `other` is dynamic-sized, then this function CHECKs if `other` is larger
    // than this span.
    constexpr void copy_prefix_from(span<const T> other)
    //requires(!std::is_const_v<T>)
    {
        return first(other.size()).copy_from(other);
    }

    // Compares two spans for equality by comparing the objects pointed to by the
    // spans. The operation is defined for spans of different types as long as the
    // types are themselves comparable.
    //
    // For primitive types, this replaces the less safe `memcmp` function, where
    // `memcmp(a.data(), b.data(), a.size()) == 0` can be written as `a == b` and
    // can no longer go outside the bounds of `b`. Otherwise, it replaced
    // std::equal or std::ranges::equal when working with spans, and when no
    // projection is needed.
    //
    // If the spans are of different sizes, they are not equal. If both spans are
    // empty, they are always equal (even though their data pointers may differ).
    //
    // # Implementation note
    // The non-template overloads allow implicit conversions to span for
    // comparison.
#if 0
  friend constexpr bool operator==(span lhs, span rhs)
    requires(std::is_const_v<T>&& std::equality_comparable<T>)
  {
    return internal::span_eq(span<const T>(lhs), span<const T>(rhs));
  }
  friend constexpr bool operator==(span lhs, span<const T> rhs)
    requires(!std::is_const_v<T>&& std::equality_comparable<const T>)
  {
    return internal::span_eq(span<const T>(lhs), span<const T>(rhs));
  }
  template <class U, size_t M>
    requires(std::equality_comparable_with<const T, const U>)
  friend constexpr bool operator==(span lhs, span<U, M> rhs) {
    return internal::span_eq(span<const T>(lhs), span<const U, M>(rhs));
  }
#endif
    // Compares two spans for ordering by comparing the objects pointed to by the
    // spans. The operation is defined for spans of different types as long as the
    // types are themselves ordered via `<=>`.
    //
    // For primitive types, this replaces the less safe `memcmp` function, where
    // `memcmp(a.data(), b.data(), a.size()) < 0` can be written as `a < b` and
    // can no longer go outside the bounds of `b`.
    //
    // If both spans are empty, they are always equal (even though their data
    // pointers may differ).
    //
    // # Implementation note
    // The non-template overloads allow implicit conversions to span for
    // comparison.
#if 0
  friend constexpr auto operator<=>(span lhs, span rhs)
    requires(std::is_const_v<T>&& std::three_way_comparable<T>)
  {
    return internal::span_cmp(span<const T>(lhs), span<const T>(rhs));
  }
  friend constexpr auto operator<=>(span lhs, span<const T> rhs)
    requires(!std::is_const_v<T>&& std::three_way_comparable<const T>)
  {
    return internal::span_cmp(span<const T>(lhs), span<const T>(rhs));
  }
  template <class U, size_t M>
    requires(std::three_way_comparable_with<const T, const U>)
  friend constexpr auto operator<=>(span lhs, span<U, M> rhs) {
    return internal::span_cmp(span<const T>(lhs), span<const U, M>(rhs));
  }
#endif

private:
    // This field is not a raw_ptr<> since span is mostly used for stack
    // variables. Use `raw_span` instead for class fields, which does use
    // raw_ptr<> internally.
    InternalPtrType data_ = nullptr;
    size_t size_ = 0;
};
//--

// [span.objectrep], views of object representation
template <typename T, size_t X> span<const uint8_t, (X == dynamic_extent ? dynamic_extent : sizeof(T) * X)> as_bytes(span<T, X> s) noexcept
{
    return { reinterpret_cast<const uint8_t*>(s.data()), s.size_bytes() };
}

template <typename T, size_t X, typename = std::enable_if_t<!std::is_const<T>::value>>
span<uint8_t, (X == dynamic_extent ? dynamic_extent : sizeof(T) * X)> as_writable_bytes(span<T, X> s) noexcept
{
    return { reinterpret_cast<uint8_t*>(s.data()), s.size_bytes() };
}

// Type-deducing helpers for constructing a span.
template <int&... ExplicitArgumentBarrier, typename It> constexpr auto make_span(It it, size_t size) noexcept
{
    using T = std::remove_reference_t<iter_reference_t<It>>;
    return span<T>(it, size);
}

template <int&... ExplicitArgumentBarrier, typename It, typename End, typename = std::enable_if_t<!std::is_convertible_v<End, size_t>>>
constexpr auto make_span(It it, End end) noexcept
{
    using T = std::remove_reference_t<iter_reference_t<It>>;
    return span<T>(it, end);
}

// make_span utility function that deduces both the span's value_type and extent
// from the passed in argument.
//
// Usage: auto span = base::make_span(...);
template <int&... ExplicitArgumentBarrier, typename Container> constexpr auto make_span(Container&& container) noexcept
{
    using T = std::remove_pointer_t<decltype(std::data(std::declval<Container>()))>;
    using Extent = internal::Extent<Container>;
    return span<T, Extent::value>(std::forward<Container>(container));
}

// make_span utility functions that allow callers to explicit specify the span's
// extent, the value_type is deduced automatically. This is useful when passing
// a dynamically sized container to a method expecting static spans, when the
// container is known to have the correct size.
//
// Note: This will CHECK that N indeed matches size(container).
//
// Usage: auto static_span = base::make_span<N>(...);
template <size_t N, int&... ExplicitArgumentBarrier, typename It> constexpr auto make_span(It it, size_t size) noexcept
{
    using T = std::remove_reference_t<iter_reference_t<It>>;
    return span<T, N>(it, size);
}

template <size_t N, int&... ExplicitArgumentBarrier, typename It, typename End, typename = std::enable_if_t<!std::is_convertible_v<End, size_t>>>
constexpr auto make_span(It it, End end) noexcept
{
    using T = std::remove_reference_t<iter_reference_t<It>>;
    return span<T, N>(it, end);
}

template <size_t N, int&... ExplicitArgumentBarrier, typename Container> constexpr auto make_span(Container&& container) noexcept
{
    using T = std::remove_pointer_t<decltype(std::data(std::declval<Container>()))>;
    return span<T, N>(std::data(container), std::size(container));
}

template <int&... ExplicitArgumentBarrier, typename Spannable> constexpr auto as_byte_span(const Spannable& arg)
{
    return as_bytes(span(arg));
}

} // namespace base

// EXTENT returns the size of any type that can be converted to a |base::span|
// with definite extent, i.e. everything that is a contiguous storage of some
// sort with static size. Specifically, this works for std::array in a constexpr
// context. Note:
//   * |std::size| should be preferred for plain arrays.
//   * In run-time contexts, functions such as |std::array::size| should be
//     preferred.
#define EXTENT(x) ::base::internal::must_not_be_dynamic_extent<decltype(::base::make_span(x))::extent>()

#endif // BASE_CONTAINERS_SPAN_H_
