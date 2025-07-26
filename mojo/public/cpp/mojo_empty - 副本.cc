
#include "mojo/public/cpp/system/handle.h"
#include "mojo/public/cpp/system/buffer.h"
#include "mojo/public/cpp/system/data_pipe_drainer.h"
#include "mojo/public/cpp/system/wait.h"
#include "mojo/public/cpp/bindings/scoped_interface_endpoint_handle.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "mojo/public/cpp/bindings/sync_handle_watcher.h"
#include "mojo/public/cpp/bindings/associated_group.h"
#include "mojo/public/cpp/bindings/generic_pending_receiver.h"
#include "mojo/public/cpp/bindings/async_flusher.h"
#include "mojo/public/cpp/bindings/receiver_set.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/receiver_set.h"
#include "mojo/public/cpp/bindings/message.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/interface_ptr_state.h"
#include "mojo/public/cpp/bindings/lib/message_quota_checker.h"
#include "mojo/public/cpp/bindings/lib/binding_state.h"
#include "mojo/public/cpp/bindings/lib/pending_remote_state.h"
#include "mojo/public/cpp/bindings/lib/unserialized_message_context.h"
#include "mojo/public/cpp/bindings/lib/pending_receiver_state.h"
#include "mojo/public/cpp/bindings/lib/associated_interface_ptr_state.h"
#include "mojo/public/cpp/base/big_buffer_mojom_traits.h"
#include "mojo/public/cpp/base/big_buffer.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared-internal.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared.h"
#include "skia/public/mojom/image_info.mojom-shared.h"

#include "third_party/blink/public/mojom/messaging/cloneable_message.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/page_state/page_state.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/page_state/page_state.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/message_port_descriptor.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/array_buffer/array_buffer_contents.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/task_attribution_id.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-shared-internal.h"
#include "third_party/blink/public/mojom/messaging/user_activation_snapshot.mojom-shared-internal.h"
#include "mojo/public/mojom/base/big_buffer.mojom-shared-internal.h"
#include "mojo/public/mojom/base/string16.mojom-shared-internal.h"
#include "mojo/public/mojom/base/time.mojom-shared-internal.h"
#include "mojo/public/mojom/base/unguessable_token.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojom/geometry.mojom-shared-internal.h"
#include "skia/public/mojom/image_info.mojom-shared-internal.h"
#include "skia/public/mojom/bitmap.mojom-shared-internal.h"
#include "url/mojom/origin.mojom-shared-internal.h"
#include "services/network/public/mojom/content_security_policy.mojom.h"
#include "services/network/public/mojom/content_security_policy.mojom-blink.h"
#include "services/network/public/mojom/timing_allow_origin.mojom.h"
#include "services/network/public/mojom/timing_allow_origin.mojom-blink.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom-blink.h"
#include "third_party/blink/public/mojom/page_state/page_state.mojom.h"
#include "third_party/blink/public/mojom/choosers/file_chooser.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink.h"
#include "third_party/blink/renderer/core/mojo/mojo_watcher.h"
#include "third_party/blink/renderer/core/mojo/test/mojo_interface_request_event.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_union_arraybuffer_arraybufferview.h"
#include "services/media_session/public/mojom/media_session.mojom-blink.h"
#include "services/viz/public/mojom/compositing/frame_sink_bundle.mojom-blink.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "third_party/skia/include/core/SkAlphaType.h"

// mojo_base::BigBufferView __cdecl mojo::StructTraits<blink::mojom::CloneableMessageDataView, blink::CloneableMessage>::encoded_message(blink::CloneableMessage&)
// mojo_base::BigBufferView __cdecl mojo::StructTraits<skia::mojom::BitmapN32DataView, SkBitmap>::pixel_data(SkBitmap const&)
//mojo::PendingRemote<network::mojom::URLLoaderFactory> __cdecl network::NotImplementedURLLoaderFactory::Create(void)
//mojo::ScopedHandleBase<mojo::MessagePipeHandle> __cdecl mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::pipe_handle(blink::MessagePortDescriptor&)
//blink::MojoHandle::MojoHandle(mojo::ScopedHandleBase<mojo::Handle>)

void ::blink::mojom::Element::set_bytes(std::vector<unsigned char, std::allocator<unsigned char> >)
{
  *(int*)1 = 1;
}
void blink::mojom::Element::set_file(mojo::StructPtr<::blink::mojom::File>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::DataElement::set_blob(mojo::StructPtr<::blink::mojom::blink::DataElementBlob>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::DataElement::set_bytes(mojo::StructPtr<::blink::mojom::blink::DataElementBytes>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::DataElement::set_file(mojo::StructPtr<::blink::mojom::blink::DataElementFile>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::FileChooserFileInfo::set_file_system(mojo::StructPtr<::blink::mojom::blink::FileSystemFileInfo>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::FileChooserFileInfo::set_native_file(mojo::StructPtr<::blink::mojom::blink::NativeFileInfo>) {
  *(int*)1 = 1;
}
void blink::mojom::blink::PermissionDescriptorExtension::set_storage_access(mojo::StructPtr<::blink::mojom::blink::StorageAccessPermissionDescriptor>) {
  *(int*)1 = 1;
}

void mojo::ReportBadMessage(base::BasicStringPiece<char, struct std::char_traits<char> >) {
  *(int*)1 = 1;
}
void mojo::internal::SerializeHandle(mojo::ScopedHandleBase<mojo::Handle>, mojo::Message&, struct mojo::internal::Handle_Data&) {
  *(int*)1 = 1;
}
void mojo::internal::SerializeInterfaceInfo(mojo::ScopedHandleBase<mojo::MessagePipeHandle>, unsigned int, mojo::Message&, struct mojo::internal::Interface_Data&) {
  *(int*)1 = 1;
}

mojo::ScopedHandleBase<mojo::SharedBufferHandle> __cdecl mojo::SharedBufferHandle::Create(unsigned __int64) {
  *(int*)1 = 1;
  return mojo::ScopedHandleBase<mojo::SharedBufferHandle>();
}
mojo::ScopedHandleBase<mojo::SharedBufferHandle> __cdecl mojo::StructTraits<mojo_base::mojom::BigBufferSharedMemoryRegionDataView, mojo_base::internal::BigBufferSharedMemoryRegion>::buffer_handle(mojo_base::internal::BigBufferSharedMemoryRegion&) {
  *(int*)1 = 1;
  return mojo::ScopedHandleBase<mojo::SharedBufferHandle>();
}

mojo_base::internal::BigBufferSharedMemoryRegion& __cdecl mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::shared_memory(mojo_base::BigBuffer&)
{
  *(int*)1 = 1;
  mojo_base::internal::BigBufferSharedMemoryRegion* reg = new mojo_base::internal::BigBufferSharedMemoryRegion();
  return *reg;
}

mojo_base::internal::BigBufferSharedMemoryRegion& __cdecl mojo::UnionTraits< mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::shared_memory(mojo_base::BigBufferView&)
{
  *(int*)1 = 1;
  mojo_base::internal::BigBufferSharedMemoryRegion* reg = new mojo_base::internal::BigBufferSharedMemoryRegion();
  return *reg;
}

unsigned __int64 mojo::ReceiverSetState::Add(std::unique_ptr<mojo::ReceiverSetState::ReceiverState, std::default_delete<mojo::ReceiverSetState::ReceiverState> >)
{
  *(int*)1 = 1;
  return 0;
}
unsigned char const* mojo::Message::payload(void)const
{
  *(int*)1 = 1;
  return 0;
}

unsigned int mojo::Message::payload_num_bytes(void)const
{
  *(int*)1 = 1;
  return 0;
}
unsigned int mojo::SimpleWatcher::Arm(unsigned int*, mojo::HandleSignalsState*)
{
  *(int*)1 = 1;
  return 0;
}
unsigned int mojo::SimpleWatcher::Watch(mojo::Handle, unsigned int, unsigned int, base::RepeatingCallback<void __cdecl(unsigned int, mojo::HandleSignalsState const&)>)
{
  *(int*)1 = 1;
  return 0;
}
unsigned int mojo::internal::Buffer::Allocate(unsigned int)
{
  *(int*)1 = 1;
  return 0;
}

std::string mojo::internal::MakeMessageWithArrayIndex(char const*, unsigned int, unsigned int)
{
  *(int*)1 = 1;
  return "";
}

std::string mojo::internal::MakeMessageWithExpectedArraySize(char const*, unsigned int, unsigned int)
{
  *(int*)1 = 1;
  return "";
}

mojo::internal::AssociatedReceiverBase::~AssociatedReceiverBase(void)
{
  *(int*)1 = 1;
}
mojo::ScopedInterfaceEndpointHandle mojo::internal::AssociatedInterfacePtrStateBase::PassHandle(void)
{
  *(int*)1 = 1;
  return mojo::ScopedInterfaceEndpointHandle();
}
mojo::internal::PendingRemoteState mojo::internal::InterfacePtrStateBase::Unbind(void)
{
  *(int*)1 = 1;
  return mojo::internal::PendingRemoteState();
}

mojo::AssociatedGroup::AssociatedGroup(mojo::AssociatedGroup const&) {
  *(int*)1 = 1;
}
mojo::AssociatedGroup::~AssociatedGroup(void) {
  *(int*)1 = 1;
}
mojo::AsyncFlusher::AsyncFlusher(mojo::AsyncFlusher&&) {
  *(int*)1 = 1;
}
mojo::AsyncFlusher::AsyncFlusher(void) {
  *(int*)1 = 1;
}
mojo::AsyncFlusher::~AsyncFlusher(void) {
  *(int*)1 = 1;
}

mojo::Connector::Connector(mojo::ScopedHandleBase<mojo::MessagePipeHandle>, enum mojo::Connector::ConnectorConfig, char const*) {
  *(int*)1 = 1;
}
mojo::Connector::Connector(mojo::ScopedHandleBase<mojo::MessagePipeHandle>, enum mojo::Connector::ConnectorConfig, scoped_refptr<base::SequencedTaskRunner>, char const*) {
  *(int*)1 = 1;
}

mojo::DataPipeDrainer::DataPipeDrainer(mojo::DataPipeDrainer::Client* client, mojo::ScopedDataPipeConsumerHandle source)
  : client_(client)
  , source_(std::move(source))
  , handle_watcher_(FROM_HERE, mojo::SimpleWatcher::ArmingPolicy::AUTOMATIC, base::SequencedTaskRunnerHandle::Get()) {
  *(int*)1 = 1;
}

mojo::DataPipeDrainer::~DataPipeDrainer(void) {
  *(int*)1 = 1;
}
mojo::GenericPendingReceiver::GenericPendingReceiver(base::BasicStringPiece<char, std::char_traits<char> >, mojo::ScopedHandleBase<mojo::MessagePipeHandle>) {
  *(int*)1 = 1;
}
mojo::GenericPendingReceiver::GenericPendingReceiver(mojo::GenericPendingReceiver&&) {
  *(int*)1 = 1;
}
mojo::GenericPendingReceiver::~GenericPendingReceiver(void) {
  *(int*)1 = 1;
}
mojo::Message::Message(mojo::Message&&) {
  *(int*)1 = 1;
}
mojo::Message::Message(std::unique_ptr<mojo::internal::UnserializedMessageContext, std::default_delete<mojo::internal::UnserializedMessageContext> >, unsigned int) {
  *(int*)1 = 1;
}
mojo::Message::Message(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, 
  std::vector<mojo::ScopedHandleBase<mojo::Handle>, std::allocator<mojo::ScopedHandleBase<mojo::Handle> > >*) {
  *(int*)1 = 1;
}
mojo::Message::Message(void) {
  *(int*)1 = 1;
}
mojo::Message::~Message(void) {
  *(int*)1 = 1;
}
mojo::PendingFlush::PendingFlush(mojo::AsyncFlusher*) {
  *(int*)1 = 1;
}
mojo::PendingFlush::PendingFlush(mojo::PendingFlush&&) {
  *(int*)1 = 1;
}
mojo::PendingFlush::~PendingFlush(void) {
  *(int*)1 = 1;
}

mojo::ReceiverSetState::Entry::~Entry(void) {
  *(int*)1 = 1;
}
mojo::ReceiverSetState::ReceiverSetState(void) {
  *(int*)1 = 1;
}
mojo::ReceiverSetState::~ReceiverSetState(void) {
  *(int*)1 = 1;
}

class mojo::ScopedInterfaceEndpointHandle::State
  : public base::RefCountedThreadSafe<mojo::ScopedInterfaceEndpointHandle::State> {
public:
  mojo::ScopedInterfaceEndpointHandle::State() = default;

  mojo::ScopedInterfaceEndpointHandle::State(InterfaceId id, scoped_refptr<AssociatedGroupController> group_controller) {}

  mojo::ScopedInterfaceEndpointHandle::State(const State&) = delete;
  mojo::ScopedInterfaceEndpointHandle::State& operator=(const ScopedInterfaceEndpointHandle::State&) = delete;
};

class mojo::SimpleWatcher::Context : public base::RefCountedThreadSafe<mojo::SimpleWatcher::Context> {
public:
  mojo::SimpleWatcher::Context(const Context&) = delete;
  mojo::SimpleWatcher::Context& operator=(const Context&) = delete;
};

mojo::ScopedInterfaceEndpointHandle::ScopedInterfaceEndpointHandle(mojo::ScopedInterfaceEndpointHandle&&) {
  *(int*)1 = 1;
}
mojo::ScopedInterfaceEndpointHandle::ScopedInterfaceEndpointHandle(void) {
  *(int*)1 = 1;
}

mojo::SimpleWatcher::SimpleWatcher(const base::Location& from_here,
  mojo::SimpleWatcher::ArmingPolicy arming_policy,
  scoped_refptr<base::SequencedTaskRunner> runner,
  const char* handler_tag)
  : arming_policy_(arming_policy)
  , task_runner_(std::move(runner))
  , is_default_task_runner_(base::ThreadTaskRunnerHandle::IsSet() && task_runner_ == base::ThreadTaskRunnerHandle::Get())
  , handler_tag_(handler_tag ? handler_tag : from_here.file_name()) {
  *(int*)1 = 1;
}
mojo::SimpleWatcher::~SimpleWatcher(void) {
  *(int*)1 = 1;
}
mojo::internal::AssociatedInterfacePtrStateBase::AssociatedInterfacePtrStateBase(void) {
  *(int*)1 = 1;
}
mojo::internal::AssociatedInterfacePtrStateBase::~AssociatedInterfacePtrStateBase(void) {
  *(int*)1 = 1;
}

mojo::internal::AssociatedReceiverBase::AssociatedReceiverBase(void) {
  *(int*)1 = 1;
}
mojo::internal::BindingStateBase::BindingStateBase(void) {
  *(int*)1 = 1;
}
mojo::internal::BindingStateBase::~BindingStateBase(void) {
  *(int*)1 = 1;
}
mojo::internal::InterfacePtrStateBase::InterfacePtrStateBase(void) {
  *(int*)1 = 1;
}
mojo::internal::InterfacePtrStateBase::~InterfacePtrStateBase(void) {
  *(int*)1 = 1;
}
mojo::internal::PendingReceiverState::PendingReceiverState(mojo::ScopedHandleBase<mojo::MessagePipeHandle>) {
  *(int*)1 = 1;
}
mojo::internal::PendingReceiverState::PendingReceiverState(mojo::internal::PendingReceiverState&&) noexcept {
  *(int*)1 = 1;
}
mojo::internal::PendingReceiverState::PendingReceiverState(void) {
  *(int*)1 = 1;
}
mojo::internal::PendingReceiverState::~PendingReceiverState(void) {
  *(int*)1 = 1;
}
mojo::internal::PendingRemoteState::PendingRemoteState(mojo::ScopedHandleBase<mojo::MessagePipeHandle>, unsigned int) {
  *(int*)1 = 1;
}
mojo::internal::PendingRemoteState::PendingRemoteState(mojo::internal::PendingRemoteState&&) noexcept {
  *(int*)1 = 1;
}
mojo::internal::PendingRemoteState::PendingRemoteState(void) {
  *(int*)1 = 1;
}
mojo::internal::PendingRemoteState::~PendingRemoteState(void) {
  *(int*)1 = 1;
}
mojo::internal::UnserializedMessageContext::UnserializedMessageContext(mojo::internal::UnserializedMessageContext::Tag const*, unsigned int, unsigned int) {
  *(int*)1 = 1;
}

mojo::internal::ValidationContext::ValidationContext(const void* data,
  size_t data_num_bytes,
  size_t num_handles,
  size_t num_associated_endpoint_handles,
  mojo::Message* message,
  const char* description,
  int stack_depth,
  mojo::internal::ValidationContext::ValidatorType validator_type)
  : message_(message),
  description_(description),
  validator_type_(validator_type),
  data_begin_(reinterpret_cast<uintptr_t>(data)),
  data_end_(data_begin_ + data_num_bytes),
  handle_begin_(0),
  handle_end_(static_cast<uint32_t>(num_handles)),
  associated_endpoint_handle_begin_(0),
  associated_endpoint_handle_end_(static_cast<uint32_t>(num_associated_endpoint_handles)),
  stack_depth_(stack_depth) {
  *(int*)1 = 1;
}
mojo::internal::ValidationContext::~ValidationContext(void) {
  *(int*)1 = 1;
}

bool mojo::ScopedInterfaceEndpointHandle::is_valid(void)const {
  *(int*)1 = 1;
  return false;
}
bool mojo::SimpleWatcher::IsWatching(void)const {
  *(int*)1 = 1;
  return false;
}
bool mojo::internal::BindingStateBase::HasAssociatedInterfaces(void)const {
  *(int*)1 = 1;
  return false;
}
bool mojo::internal::BindingStateBase::WaitForIncomingMethodCall(void) {
  *(int*)1 = 1;
  return false;
}
bool mojo::internal::MultiplexRouter::HasAssociatedEndpoints(void)const {
  *(int*)1 = 1;
  return false;
}
// 
void mojo::Connector::StartReceiving(scoped_refptr<base::SequencedTaskRunner>, bool) {
  *(int*)1 = 1;
}

void mojo::Message::SerializeHandles(mojo::AssociatedGroupController*) {
  *(int*)1 = 1;
}

void mojo::Message::SerializeIfNecessary(void) {
  *(int*)1 = 1;
}

void mojo::ScopedInterfaceEndpointHandle::reset(void) {
  *(int*)1 = 1;
}

void mojo::SimpleWatcher::ArmOrNotify(void) {
  *(int*)1 = 1;
}

void mojo::SimpleWatcher::Cancel(void) {
  *(int*)1 = 1;
}

void mojo::internal::AssociatedReceiverBase::FlushForTesting(void) {
  *(int*)1 = 1;
}
void mojo::internal::AssociatedReceiverBase::ResetWithReason(unsigned int, base::BasicStringPiece<char, std::char_traits<char> >) {
  *(int*)1 = 1;
}
void mojo::internal::AssociatedReceiverBase::SetFilter(std::unique_ptr<mojo::MessageFilter, std::default_delete<mojo::MessageFilter> >) {
  *(int*)1 = 1;
}
void mojo::internal::AssociatedReceiverBase::reset(void) {
  *(int*)1 = 1;
}
void mojo::internal::AssociatedReceiverBase::set_disconnect_handler(base::OnceCallback<void __cdecl(void)>) {
  *(int*)1 = 1;
}
void mojo::internal::AssociatedReceiverBase::set_disconnect_with_reason_handler(base::OnceCallback<void __cdecl(unsigned int, std::string const&)>) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::Close(void) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::CloseWithReason(unsigned int, base::BasicStringPiece<char, std::char_traits<char> >) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::EnableBatchDispatch(void) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::FlushForTesting(void) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::PauseIncomingMethodCallProcessing(void) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::ResumeIncomingMethodCallProcessing(void) {
  *(int*)1 = 1;
}
void mojo::internal::BindingStateBase::SetFilter(std::unique_ptr<mojo::MessageFilter, std::default_delete<mojo::MessageFilter> >) {
  *(int*)1 = 1;
}

bool mojo::MessageReceiver::PrefersSerializedMessages(void) {
  *(int*)1 = 1;
  return false;
}

mojo::internal::UnserializedMessageContext::~UnserializedMessageContext(void) {
  *(int*)1 = 1;
}

mojo::internal::PendingReceiverState& mojo::internal::PendingReceiverState::operator=(mojo::internal::PendingReceiverState&&) noexcept {
  *(int*)1 = 1;
  mojo::internal::PendingReceiverState* state = new mojo::internal::PendingReceiverState();
  return *state;
}

mojo::internal::PendingRemoteState& mojo::internal::PendingRemoteState::operator=(mojo::internal::PendingRemoteState&&) noexcept {
  *(int*)1 = 1;
  mojo::internal::PendingRemoteState* state = new mojo::internal::PendingRemoteState();
  return *state;
}

void mojo::ScopedInterfaceEndpointHandle::CreatePairPendingAssociation(mojo::ScopedInterfaceEndpointHandle*, mojo::ScopedInterfaceEndpointHandle*) {
  *(int*)1 = 1;
}

mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag 
mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBuffer>::GetTag(mojo_base::BigBuffer const&)
{
  *(int*)1 = 1;
  return mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag::kBytes;
}
mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag 
mojo::UnionTraits<mojo_base::mojom::BigBufferDataView, mojo_base::BigBufferView>::GetTag(mojo_base::BigBufferView const&)
{
  *(int*)1 = 1;
  return mojo_base::mojom::internal::BigBuffer_Data::BigBuffer_Tag::kBytes;
}

unsigned int __cdecl mojo::StructTraits<mojo_base::mojom::BigBufferSharedMemoryRegionDataView, mojo_base::internal::BigBufferSharedMemoryRegion>::size(mojo_base::internal::BigBufferSharedMemoryRegion const&)
{
  *(int*)1 = 1;
  return 0;
}

bool mojo::Connector::Accept(mojo::Message*)
{
  *(int*)1 = 1;
  return false;
}

bool mojo::Connector::PrefersSerializedMessages(void)
{
  *(int*)1 = 1;
  return false;
}

mojo::ScopedHandleBase<mojo::MessagePipeHandle> mojo::Connector::PassMessagePipe(void) {
  *(int*)1 = 1;
  return mojo::ScopedHandleBase<mojo::MessagePipeHandle>();
}

mojo::ScopedHandleBase<mojo::MessagePipeHandle> mojo::GenericPendingReceiver::PassPipe(void) {
  *(int*)1 = 1;
  return mojo::ScopedHandleBase<mojo::MessagePipeHandle>();
}

mojo::ScopedInterfaceEndpointHandle& mojo::ScopedInterfaceEndpointHandle::operator=(mojo::ScopedInterfaceEndpointHandle&& other) {
  *(int*)1 = 1; 
  return other;
}

char const* mojo::internal::ValidationErrorToString(enum mojo::internal::ValidationError)
{
  *(int*)1 = 1;
  return "";
}

media_session::mojom::blink::MediaPosition::MediaPosition(double, class base::TimeDelta, class base::TimeDelta, class base::TimeTicks, bool) {
  *(int*)1 = 1;
}
mojo::ConnectionGroup::Ref::Ref(void) {
  *(int*)1 = 1;
}
mojo::ConnectionGroup::Ref::~Ref(void) {
  *(int*)1 = 1;
}
mojo::MessageHeaderValidator::MessageHeaderValidator(void) {
  *(int*)1 = 1;
}
mojo::ScopedInterfaceEndpointHandle::~ScopedInterfaceEndpointHandle(void) {
  *(int*)1 = 1;
}
mojo::internal::Buffer::Buffer(void) {
  *(int*)1 = 1;
}
mojo::internal::Buffer::~Buffer(void) {
  *(int*)1 = 1;
}

viz::mojom::blink::BundledFrameSubmissionData::BundledFrameSubmissionData(void) {
  *(int*)1 = 1;
}

unsigned int blink::MojoWatcher::cancel(void) {
  *(int*)1 = 1;
  return 0;
}

unsigned int blink::MojoHandle::writeMessage(blink::V8UnionArrayBufferOrArrayBufferView const*, blink::HeapVector<cppgc::internal::BasicMember<blink::MojoHandle, 
  cppgc::internal::StrongMemberTag, cppgc::internal::DijkstraWriteBarrierPolicy, cppgc::internal::DisabledCheckingPolicy>, 0> const&) {
  *(int*)1 = 1;
  return 0;
}

blink::MojoInterfaceRequestEvent::~MojoInterfaceRequestEvent(void) {
  *(int*)1 = 1;
}

// skia::mojom::AlphaType mojo::EnumTraits<skia::mojom::AlphaType, SkAlphaType>::ToMojom(SkAlphaType)
// {
//   *(int*)1 = 1;
//   return skia::mojom::AlphaType::UNKNOWN;
// }
// 
//unsigned __int64 __cdecl mojo::StructTraits<blink::mojom::MessagePortDescriptorDataView, blink::MessagePortDescriptor>::sequence_number(blink::MessagePortDescriptor&)
// unsigned int __cdecl mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::height(SkImageInfo const&)
// unsigned int __cdecl mojo::StructTraits<skia::mojom::ImageInfoDataView, SkImageInfo>::width(SkImageInfo const&)

blink::mojom::internal::CloneableMessage_Data::CloneableMessage_Data() : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::DEPRECATED_FileSystemFile_Data::DEPRECATED_FileSystemFile_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::File_Data::File_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::FrameState_Data::FrameState_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::HttpBody_Data::HttpBody_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::MessagePortDescriptor_Data::MessagePortDescriptor_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::PageState_Data::PageState_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::RequestBody_Data::RequestBody_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::SerializedArrayBufferContents_Data::SerializedArrayBufferContents_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::SerializedBlob_Data::SerializedBlob_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::TaskAttributionId_Data::TaskAttributionId_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::TransferableMessage_Data::TransferableMessage_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::UserActivationSnapshot_Data::UserActivationSnapshot_Data(void) : header_({ sizeof(*this), 0 }) {}
blink::mojom::internal::ViewState_Data::ViewState_Data(void) : header_({ sizeof(*this), 0 }) {}
gfx::mojom::internal::PointF_Data::PointF_Data(void) : header_({ sizeof(*this), 0 }) {}
gfx::mojom::internal::Point_Data::Point_Data(void) : header_({ sizeof(*this), 0 }) {}
mojo_base::mojom::internal::BigBufferSharedMemoryRegion_Data::BigBufferSharedMemoryRegion_Data(void) : header_({ sizeof(*this), 0 }) {}
mojo_base::mojom::internal::String16_Data::String16_Data(void) : header_({ sizeof(*this), 0 }) {}
mojo_base::mojom::internal::Time_Data::Time_Data(void) : header_({ sizeof(*this), 0 }) {}
mojo_base::mojom::internal::UnguessableToken_Data::UnguessableToken_Data(void) : header_({ sizeof(*this), 0 }) {}
skia::mojom::internal::BitmapN32ImageInfo_Data::BitmapN32ImageInfo_Data(void) : header_({ sizeof(*this), 0 }) {}
skia::mojom::internal::BitmapN32_Data::BitmapN32_Data(void) : header_({ sizeof(*this), 0 }) {}
url::mojom::internal::Origin_Data::Origin_Data(void) : header_({ sizeof(*this), 0 }) {}

void network::mojom::AllowCSPFromHeaderValue::set_allow_star(bool allow_star) {
  *(int*)1 = 1;
}
void network::mojom::AllowCSPFromHeaderValue::set_origin(const ::url::Origin& origin) {
  *(int*)1 = 1;
}
void network::mojom::AllowCSPFromHeaderValue::set_error_message(const std::string& error_message) {
  *(int*)1 = 1;
}
void network::mojom::AllowCSPFromHeaderValue::DestroyActive() {
  *(int*)1 = 1;
}

void network::mojom::blink::AllowCSPFromHeaderValue::set_allow_star(bool) {
  *(int*)1 = 1;
}
void network::mojom::blink::AllowCSPFromHeaderValue::set_error_message(WTF::String const&) {
  *(int*)1 = 1;
}
void network::mojom::blink::AllowCSPFromHeaderValue::set_origin(scoped_refptr<::blink::SecurityOrigin const > const&) {
  *(int*)1 = 1;
}

void network::mojom::TimingAllowOrigin::set_serialized_origins(std::vector<std::string> serialized_origins) {
  *(int*)1 = 1;
}
void network::mojom::TimingAllowOrigin::set_all(unsigned char) {
  *(int*)1 = 1;
}

void network::mojom::blink::TimingAllowOrigin::set_all(unsigned char) {
  *(int*)1 = 1;
}
void network::mojom::blink::TimingAllowOrigin::set_serialized_origins(WTF::Vector<WTF::String, 0, WTF::PartitionAllocator>) {
  *(int*)1 = 1;
}

unsigned int mojo::Wait(mojo::Handle, unsigned int, unsigned int, MojoHandleSignalsState*)
{
  *(int*)1 = 1;

  return 0;
}

// const char AssociatedInterfaceProvider::Name_[] = "blink.mojom.AssociatedInterfaceProvider";
// public: static char const* const blink::mojom::Blob::Name_
// public: static char const* const blink::mojom::BlobRegistry::Name_
// public: static char const* const blink::mojom::BrowserInterfaceBroker::Name_
// public: static char const* const blink::mojom::CodeCacheHost::Name_
// public: static char const* const blink::mojom::FileSystemAccessTransferToken::Name_
// public: static char const* const blink::mojom::ResourceLoadInfoNotifier::Name_
// public: static char const* const blink::mojom::blink::AnchorElementInteractionHost::Name_
// public: static char const* const blink::mojom::blink::AnchorElementMetricsHost::Name_
// public: static char const* const blink::mojom::blink::AnnotationAgentContainer::Name_
// public: static char const* const blink::mojom::blink::AnnotationAgentHost::Name_
// public: static char const* const blink::mojom::blink::AttributionDataHost::Name_
// public: static char const* const blink::mojom::blink::BackForwardCacheControllerHost::Name_
// public: static char const* const blink::mojom::blink::Blob::Name_
// public: static char const* const blink::mojom::blink::BlobRegistry::Name_
// public: static char const* const blink::mojom::blink::BlobURLStore::Name_
// public: static char const* const blink::mojom::blink::BlobURLToken::Name_
// public: static char const* const blink::mojom::blink::ClipboardHost::Name_
// public: static char const* const blink::mojom::blink::ContentSecurityNotifier::Name_
// public: static char const* const blink::mojom::blink::ContextMenuClient::Name_
// public: static char const* const blink::mojom::blink::ConversionHost::Name_
// public: static char const* const blink::mojom::blink::DWriteFontProxy::Name_
// public: static char const* const blink::mojom::blink::DateTimeChooser::Name_
// public: static char const* const blink::mojom::blink::DedicatedWorkerHost::Name_
// public: static char const* const blink::mojom::blink::DevToolsAgentHost::Name_
// public: static char const* const blink::mojom::blink::DevToolsFrontend::Name_
// public: static char const* const blink::mojom::blink::DevToolsFrontendHost::Name_
// public: static char const* const blink::mojom::blink::DevToolsSessionHost::Name_
// public: static char const* const blink::mojom::blink::DisplayCutoutClient::Name_
// public: static char const* const blink::mojom::blink::DisplayCutoutHost::Name_
// public: static char const* const blink::mojom::blink::EmbeddedFrameSinkProvider::Name_
// public: static char const* const blink::mojom::blink::EyeDropperChooser::Name_
// public: static char const* const blink::mojom::blink::FencedFrameOwnerHost::Name_
// public: static char const* const blink::mojom::blink::FileChooser::Name_
// public: static char const* const blink::mojom::blink::FileSystemAccessDataTransferToken::Name_
// public: static char const* const blink::mojom::blink::FileUtilitiesHost::Name_
// public: static char const* const blink::mojom::blink::FindInPage::Name_
// public: static char const* const blink::mojom::blink::FindInPageClient::Name_
// public: static char const* const blink::mojom::blink::FrameWidgetHost::Name_
// public: static char const* const blink::mojom::blink::FullscreenVideoElementHandler::Name_
// public: static char const* const blink::mojom::blink::GpuDataManager::Name_
// public: static char const* const blink::mojom::blink::HighPriorityLocalFrame::Name_
// public: static char const* const blink::mojom::blink::KeepAliveHandleFactory::Name_
// public: static char const* const blink::mojom::blink::LocalFrame::Name_
// public: static char const* const blink::mojom::blink::LocalFrameHost::Name_
// public: static char const* const blink::mojom::blink::LocalMainFrame::Name_
// public: static char const* const blink::mojom::blink::LocalMainFrameHost::Name_
// public: static char const* const blink::mojom::blink::MimeRegistry::Name_
// public: static char const* const blink::mojom::blink::NoStatePrefetchProcessor::Name_
// public: static char const* const blink::mojom::blink::OomInterventionHost::Name_
// public: static char const* const blink::mojom::blink::PauseSubresourceLoadingHandle::Name_
// public: static char const* const blink::mojom::blink::PendingBeacon::Name_
// public: static char const* const blink::mojom::blink::PendingBeaconHost::Name_
// public: static char const* const blink::mojom::blink::PermissionService::Name_
// public: static char const* const blink::mojom::blink::PluginRegistry::Name_
// public: static char const* const blink::mojom::blink::PointerLockContext::Name_
// public: static char const* const blink::mojom::blink::PolicyContainerHost::Name_
// public: static char const* const blink::mojom::blink::PopupWidgetHost::Name_
// public: static char const* const blink::mojom::blink::Portal::Name_
// public: static char const* const blink::mojom::blink::PortalHost::Name_
// public: static char const* const blink::mojom::blink::ProgressClient::Name_
// public: static char const* const blink::mojom::blink::RemoteFrameHost::Name_
// public: static char const* const blink::mojom::blink::RemoteMainFrameHost::Name_
// public: static char const* const blink::mojom::blink::RendererPreferenceWatcher::Name_
// public: static char const* const blink::mojom::blink::ReportingServiceProxy::Name_
// public: static char const* const blink::mojom::blink::ServiceWorkerWorkerClientRegistry::Name_
// public: static char const* const blink::mojom::blink::SharedWorkerConnector::Name_
// public: static char const* const blink::mojom::blink::SharedWorkerHost::Name_
// public: static char const* const blink::mojom::blink::SpeculationHost::Name_
// public: static char const* const blink::mojom::blink::SurfaceEmbedder::Name_
// public: static char const* const blink::mojom::blink::TextFragmentReceiver::Name_
// public: static char const* const blink::mojom::blink::TextSuggestionHost::Name_
// public: static char const* const blink::mojom::blink::WakeLockService::Name_
// public: static char const* const blink::mojom::blink::WidgetHost::Name_
// public: static char const* const blink::mojom::blink::WidgetInputHandlerHost::Name_
// public: static char const* const blink::mojom::blink::WorkerContentSettingsProxy::Name_
// public: static char const* const blink::test::mojom::blink::AttributionReportingAutomation::Name_
// public: static char const* const cc::mojom::blink::RenderFrameMetadataObserverClient::Name_
// public: static char const* const device::mojom::blink::TimeZoneMonitor::Name_
// public: static char const* const device::mojom::blink::WakeLock::Name_
// public: static char const* const media::mojom::WatchTimeRecorder::Name_
// public: static char const* const media::mojom::blink::MediaPlayerHost::Name_
// public: static char const* const media::mojom::blink::MediaPlayerObserver::Name_
// public: static char const* const network::mojom::DataPipeGetter::Name_
// public: static char const* const network::mojom::URLLoader::Name_
// public: static char const* const network::mojom::URLLoaderClient::Name_
// public: static char const* const network::mojom::URLLoaderFactory::Name_
// public: static char const* const network::mojom::blink::ChunkedDataPipeGetter::Name_
// public: static char const* const network::mojom::blink::CrossOriginOpenerPolicyReporter::Name_
// public: static char const* const network::mojom::blink::DataPipeGetter::Name_
// public: static char const* const network::mojom::blink::RestrictedCookieManager::Name_
// public: static char const* const network::mojom::blink::TrustTokenQueryAnswerer::Name_
// public: static char const* const network::mojom::blink::URLLoaderFactory::Name_
// public: static char const* const network::mojom::blink::WebBundleHandle::Name_
// public: static char const* const performance_manager::mojom::blink::DocumentCoordinationUnit::Name_
// public: static char const* const performance_manager::mojom::blink::ProcessCoordinationUnit::Name_
// public: static char const* const viz::mojom::CompositorFrameSink::Name_
// public: static char const* const viz::mojom::blink::CompositorFrameSink::Name_
// public: static char const* const viz::mojom::blink::FrameSinkBundle::Name_