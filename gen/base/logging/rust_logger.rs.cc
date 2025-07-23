namespace logging {
namespace internal {
extern "C" {
void logging$internal$cxxbridge1$init_rust_log_crate() noexcept;
} // extern "C"

void init_rust_log_crate() noexcept
{
    logging$internal$cxxbridge1$init_rust_log_crate();
}
} // namespace internal
} // namespace logging
