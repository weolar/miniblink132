
#include "env-inl.h"
#include "node_builtins.h"
#include "node_external_reference.h"
#include "node_internals.h"

namespace node {

namespace builtins {

static const uint8_t internal_deps_acorn_acorn_walk_dist_walk_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_acorn_acorn_walk_dist_walk_resource(internal_deps_acorn_acorn_walk_dist_walk_raw, 1, nullptr);

static const uint16_t internal_deps_acorn_acorn_dist_acorn_raw[] = {
32
};

static StaticExternalTwoByteResource internal_deps_acorn_acorn_dist_acorn_resource(internal_deps_acorn_acorn_dist_acorn_raw, 1, nullptr);

static const uint8_t internal_deps_amaro_dist_index_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_amaro_dist_index_resource(internal_deps_amaro_dist_index_raw, 1, nullptr);

static const uint8_t internal_deps_cjs_module_lexer_dist_lexer_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_cjs_module_lexer_dist_lexer_resource(internal_deps_cjs_module_lexer_dist_lexer_raw, 1, nullptr);

static const uint8_t internal_deps_cjs_module_lexer_lexer_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_cjs_module_lexer_lexer_resource(internal_deps_cjs_module_lexer_lexer_raw, 1, nullptr);

static const uint8_t internal_deps_minimatch_index_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_minimatch_index_resource(internal_deps_minimatch_index_raw, 1, nullptr);

static const uint8_t internal_deps_undici_undici_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_undici_undici_resource(internal_deps_undici_undici_raw, 1, nullptr);

static const uint8_t _http_agent_raw[] = {
32
};

static StaticExternalOneByteResource _http_agent_resource(_http_agent_raw, 1, nullptr);

static const uint8_t _http_client_raw[] = {
32
};

static StaticExternalOneByteResource _http_client_resource(_http_client_raw, 1, nullptr);

static const uint8_t _http_common_raw[] = {
32
};

static StaticExternalOneByteResource _http_common_resource(_http_common_raw, 1, nullptr);

static const uint8_t _http_incoming_raw[] = {
32
};

static StaticExternalOneByteResource _http_incoming_resource(_http_incoming_raw, 1, nullptr);

static const uint8_t _http_outgoing_raw[] = {
32
};

static StaticExternalOneByteResource _http_outgoing_resource(_http_outgoing_raw, 1, nullptr);

static const uint8_t _http_server_raw[] = {
32
};

static StaticExternalOneByteResource _http_server_resource(_http_server_raw, 1, nullptr);

static const uint8_t _stream_duplex_raw[] = {
32
};

static StaticExternalOneByteResource _stream_duplex_resource(_stream_duplex_raw, 1, nullptr);

static const uint8_t _stream_passthrough_raw[] = {
32
};

static StaticExternalOneByteResource _stream_passthrough_resource(_stream_passthrough_raw, 1, nullptr);

static const uint8_t _stream_readable_raw[] = {
32
};

static StaticExternalOneByteResource _stream_readable_resource(_stream_readable_raw, 1, nullptr);

static const uint8_t _stream_transform_raw[] = {
32
};

static StaticExternalOneByteResource _stream_transform_resource(_stream_transform_raw, 1, nullptr);

static const uint8_t _stream_wrap_raw[] = {
32
};

static StaticExternalOneByteResource _stream_wrap_resource(_stream_wrap_raw, 1, nullptr);

static const uint8_t _stream_writable_raw[] = {
32
};

static StaticExternalOneByteResource _stream_writable_resource(_stream_writable_raw, 1, nullptr);

static const uint8_t _tls_common_raw[] = {
32
};

static StaticExternalOneByteResource _tls_common_resource(_tls_common_raw, 1, nullptr);

static const uint8_t _tls_wrap_raw[] = {
32
};

static StaticExternalOneByteResource _tls_wrap_resource(_tls_wrap_raw, 1, nullptr);

static const uint8_t assert_raw[] = {
32
};

static StaticExternalOneByteResource assert_resource(assert_raw, 1, nullptr);

static const uint8_t assert_strict_raw[] = {
32
};

static StaticExternalOneByteResource assert_strict_resource(assert_strict_raw, 1, nullptr);

static const uint8_t async_hooks_raw[] = {
32
};

static StaticExternalOneByteResource async_hooks_resource(async_hooks_raw, 1, nullptr);

static const uint8_t buffer_raw[] = {
32
};

static StaticExternalOneByteResource buffer_resource(buffer_raw, 1, nullptr);

static const uint8_t child_process_raw[] = {
32
};

static StaticExternalOneByteResource child_process_resource(child_process_raw, 1, nullptr);

static const uint8_t cluster_raw[] = {
32
};

static StaticExternalOneByteResource cluster_resource(cluster_raw, 1, nullptr);

static const uint8_t console_raw[] = {
32
};

static StaticExternalOneByteResource console_resource(console_raw, 1, nullptr);

static const uint8_t constants_raw[] = {
32
};

static StaticExternalOneByteResource constants_resource(constants_raw, 1, nullptr);

static const uint8_t crypto_raw[] = {
32
};

static StaticExternalOneByteResource crypto_resource(crypto_raw, 1, nullptr);

static const uint8_t dgram_raw[] = {
32
};

static StaticExternalOneByteResource dgram_resource(dgram_raw, 1, nullptr);

static const uint8_t diagnostics_channel_raw[] = {
32
};

static StaticExternalOneByteResource diagnostics_channel_resource(diagnostics_channel_raw, 1, nullptr);

static const uint8_t dns_raw[] = {
32
};

static StaticExternalOneByteResource dns_resource(dns_raw, 1, nullptr);

static const uint8_t dns_promises_raw[] = {
32
};

static StaticExternalOneByteResource dns_promises_resource(dns_promises_raw, 1, nullptr);

static const uint8_t domain_raw[] = {
32
};

static StaticExternalOneByteResource domain_resource(domain_raw, 1, nullptr);

static const uint8_t events_raw[] = {
32
};

static StaticExternalOneByteResource events_resource(events_raw, 1, nullptr);

static const uint8_t fs_raw[] = {
32
};

static StaticExternalOneByteResource fs_resource(fs_raw, 1, nullptr);

static const uint8_t fs_promises_raw[] = {
32
};

static StaticExternalOneByteResource fs_promises_resource(fs_promises_raw, 1, nullptr);

static const uint8_t http_raw[] = {
32
};

static StaticExternalOneByteResource http_resource(http_raw, 1, nullptr);

static const uint8_t http2_raw[] = {
32
};

static StaticExternalOneByteResource http2_resource(http2_raw, 1, nullptr);

static const uint8_t https_raw[] = {
32
};

static StaticExternalOneByteResource https_resource(https_raw, 1, nullptr);

static const uint8_t inspector_raw[] = {
32
};

static StaticExternalOneByteResource inspector_resource(inspector_raw, 1, nullptr);

static const uint8_t inspector_promises_raw[] = {
32
};

static StaticExternalOneByteResource inspector_promises_resource(inspector_promises_raw, 1, nullptr);

static const uint8_t internal_abort_controller_raw[] = {
32
};

static StaticExternalOneByteResource internal_abort_controller_resource(internal_abort_controller_raw, 1, nullptr);

static const uint8_t internal_assert_raw[] = {
32
};

static StaticExternalOneByteResource internal_assert_resource(internal_assert_raw, 1, nullptr);

static const uint8_t internal_assert_assertion_error_raw[] = {
32
};

static StaticExternalOneByteResource internal_assert_assertion_error_resource(internal_assert_assertion_error_raw, 1, nullptr);

static const uint8_t internal_assert_calltracker_raw[] = {
32
};

static StaticExternalOneByteResource internal_assert_calltracker_resource(internal_assert_calltracker_raw, 1, nullptr);

static const uint8_t internal_assert_myers_diff_raw[] = {
32
};

static StaticExternalOneByteResource internal_assert_myers_diff_resource(internal_assert_myers_diff_raw, 1, nullptr);

static const uint8_t internal_assert_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_assert_utils_resource(internal_assert_utils_raw, 1, nullptr);

static const uint8_t internal_async_context_frame_raw[] = {
32
};

static StaticExternalOneByteResource internal_async_context_frame_resource(internal_async_context_frame_raw, 1, nullptr);

static const uint8_t internal_async_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_async_hooks_resource(internal_async_hooks_raw, 1, nullptr);

static const uint8_t internal_async_local_storage_async_context_frame_raw[] = {
32
};

static StaticExternalOneByteResource internal_async_local_storage_async_context_frame_resource(internal_async_local_storage_async_context_frame_raw, 1, nullptr);

static const uint8_t internal_async_local_storage_async_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_async_local_storage_async_hooks_resource(internal_async_local_storage_async_hooks_raw, 1, nullptr);

static const uint8_t internal_blob_raw[] = {
32
};

static StaticExternalOneByteResource internal_blob_resource(internal_blob_raw, 1, nullptr);

static const uint8_t internal_blocklist_raw[] = {
32
};

static StaticExternalOneByteResource internal_blocklist_resource(internal_blocklist_raw, 1, nullptr);

static const uint8_t internal_bootstrap_node_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_node_resource(internal_bootstrap_node_raw, 1, nullptr);

static const uint8_t internal_bootstrap_realm_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_realm_resource(internal_bootstrap_realm_raw, 1, nullptr);

static const uint8_t internal_bootstrap_shadow_realm_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_shadow_realm_resource(internal_bootstrap_shadow_realm_raw, 1, nullptr);

static const uint8_t internal_bootstrap_switches_does_not_own_process_state_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_switches_does_not_own_process_state_resource(internal_bootstrap_switches_does_not_own_process_state_raw, 1, nullptr);

static const uint8_t internal_bootstrap_switches_does_own_process_state_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_switches_does_own_process_state_resource(internal_bootstrap_switches_does_own_process_state_raw, 1, nullptr);

static const uint8_t internal_bootstrap_switches_is_main_thread_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_switches_is_main_thread_resource(internal_bootstrap_switches_is_main_thread_raw, 1, nullptr);

static const uint8_t internal_bootstrap_switches_is_not_main_thread_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_switches_is_not_main_thread_resource(internal_bootstrap_switches_is_not_main_thread_raw, 1, nullptr);

static const uint8_t internal_bootstrap_web_exposed_wildcard_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_web_exposed_wildcard_resource(internal_bootstrap_web_exposed_wildcard_raw, 1, nullptr);

static const uint8_t internal_bootstrap_web_exposed_window_or_worker_raw[] = {
32
};

static StaticExternalOneByteResource internal_bootstrap_web_exposed_window_or_worker_resource(internal_bootstrap_web_exposed_window_or_worker_raw, 1, nullptr);

static const uint8_t internal_buffer_raw[] = {
32
};

static StaticExternalOneByteResource internal_buffer_resource(internal_buffer_raw, 1, nullptr);

static const uint8_t internal_child_process_raw[] = {
32
};

static StaticExternalOneByteResource internal_child_process_resource(internal_child_process_raw, 1, nullptr);

static const uint8_t internal_child_process_serialization_raw[] = {
32
};

static StaticExternalOneByteResource internal_child_process_serialization_resource(internal_child_process_serialization_raw, 1, nullptr);

static const uint16_t internal_cli_table_raw[] = {
32
};

static StaticExternalTwoByteResource internal_cli_table_resource(internal_cli_table_raw, 1, nullptr);

static const uint8_t internal_cluster_child_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_child_resource(internal_cluster_child_raw, 1, nullptr);

static const uint8_t internal_cluster_primary_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_primary_resource(internal_cluster_primary_raw, 1, nullptr);

static const uint8_t internal_cluster_round_robin_handle_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_round_robin_handle_resource(internal_cluster_round_robin_handle_raw, 1, nullptr);

static const uint8_t internal_cluster_shared_handle_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_shared_handle_resource(internal_cluster_shared_handle_raw, 1, nullptr);

static const uint8_t internal_cluster_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_utils_resource(internal_cluster_utils_raw, 1, nullptr);

static const uint8_t internal_cluster_worker_raw[] = {
32
};

static StaticExternalOneByteResource internal_cluster_worker_resource(internal_cluster_worker_raw, 1, nullptr);

static const uint8_t internal_console_constructor_raw[] = {
32
};

static StaticExternalOneByteResource internal_console_constructor_resource(internal_console_constructor_raw, 1, nullptr);

static const uint8_t internal_console_global_raw[] = {
32
};

static StaticExternalOneByteResource internal_console_global_resource(internal_console_global_raw, 1, nullptr);

static const uint8_t internal_constants_raw[] = {
32
};

static StaticExternalOneByteResource internal_constants_resource(internal_constants_raw, 1, nullptr);

static const uint8_t internal_crypto_aes_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_aes_resource(internal_crypto_aes_raw, 1, nullptr);

static const uint8_t internal_crypto_certificate_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_certificate_resource(internal_crypto_certificate_raw, 1, nullptr);

static const uint8_t internal_crypto_cfrg_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_cfrg_resource(internal_crypto_cfrg_raw, 1, nullptr);

static const uint8_t internal_crypto_cipher_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_cipher_resource(internal_crypto_cipher_raw, 1, nullptr);

static const uint8_t internal_crypto_diffiehellman_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_diffiehellman_resource(internal_crypto_diffiehellman_raw, 1, nullptr);

static const uint8_t internal_crypto_ec_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_ec_resource(internal_crypto_ec_raw, 1, nullptr);

static const uint8_t internal_crypto_hash_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_hash_resource(internal_crypto_hash_raw, 1, nullptr);

static const uint8_t internal_crypto_hashnames_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_hashnames_resource(internal_crypto_hashnames_raw, 1, nullptr);

static const uint8_t internal_crypto_hkdf_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_hkdf_resource(internal_crypto_hkdf_raw, 1, nullptr);

static const uint8_t internal_crypto_keygen_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_keygen_resource(internal_crypto_keygen_raw, 1, nullptr);

static const uint8_t internal_crypto_keys_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_keys_resource(internal_crypto_keys_raw, 1, nullptr);

static const uint8_t internal_crypto_mac_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_mac_resource(internal_crypto_mac_raw, 1, nullptr);

static const uint8_t internal_crypto_pbkdf2_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_pbkdf2_resource(internal_crypto_pbkdf2_raw, 1, nullptr);

static const uint8_t internal_crypto_random_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_random_resource(internal_crypto_random_raw, 1, nullptr);

static const uint8_t internal_crypto_rsa_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_rsa_resource(internal_crypto_rsa_raw, 1, nullptr);

static const uint8_t internal_crypto_scrypt_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_scrypt_resource(internal_crypto_scrypt_raw, 1, nullptr);

static const uint8_t internal_crypto_sig_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_sig_resource(internal_crypto_sig_raw, 1, nullptr);

static const uint8_t internal_crypto_util_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_util_resource(internal_crypto_util_raw, 1, nullptr);

static const uint8_t internal_crypto_webcrypto_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_webcrypto_resource(internal_crypto_webcrypto_raw, 1, nullptr);

static const uint8_t internal_crypto_webidl_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_webidl_resource(internal_crypto_webidl_raw, 1, nullptr);

static const uint8_t internal_crypto_x509_raw[] = {
32
};

static StaticExternalOneByteResource internal_crypto_x509_resource(internal_crypto_x509_raw, 1, nullptr);

static const uint8_t internal_data_url_raw[] = {
32
};

static StaticExternalOneByteResource internal_data_url_resource(internal_data_url_raw, 1, nullptr);

static const uint8_t internal_debugger_inspect_raw[] = {
32
};

static StaticExternalOneByteResource internal_debugger_inspect_resource(internal_debugger_inspect_raw, 1, nullptr);

static const uint8_t internal_debugger_inspect_client_raw[] = {
32
};

static StaticExternalOneByteResource internal_debugger_inspect_client_resource(internal_debugger_inspect_client_raw, 1, nullptr);

static const uint8_t internal_debugger_inspect_repl_raw[] = {
32
};

static StaticExternalOneByteResource internal_debugger_inspect_repl_resource(internal_debugger_inspect_repl_raw, 1, nullptr);

static const uint8_t internal_dgram_raw[] = {
32
};

static StaticExternalOneByteResource internal_dgram_resource(internal_dgram_raw, 1, nullptr);

static const uint8_t internal_dns_callback_resolver_raw[] = {
32
};

static StaticExternalOneByteResource internal_dns_callback_resolver_resource(internal_dns_callback_resolver_raw, 1, nullptr);

static const uint8_t internal_dns_promises_raw[] = {
32
};

static StaticExternalOneByteResource internal_dns_promises_resource(internal_dns_promises_raw, 1, nullptr);

static const uint8_t internal_dns_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_dns_utils_resource(internal_dns_utils_raw, 1, nullptr);

static const uint8_t internal_encoding_raw[] = {
32
};

static StaticExternalOneByteResource internal_encoding_resource(internal_encoding_raw, 1, nullptr);

static const uint8_t internal_error_serdes_raw[] = {
32
};

static StaticExternalOneByteResource internal_error_serdes_resource(internal_error_serdes_raw, 1, nullptr);

static const uint8_t internal_errors_raw[] = {
32
};

static StaticExternalOneByteResource internal_errors_resource(internal_errors_raw, 1, nullptr);

static const uint8_t internal_event_target_raw[] = {
32
};

static StaticExternalOneByteResource internal_event_target_resource(internal_event_target_raw, 1, nullptr);

static const uint8_t internal_events_abort_listener_raw[] = {
32
};

static StaticExternalOneByteResource internal_events_abort_listener_resource(internal_events_abort_listener_raw, 1, nullptr);

static const uint8_t internal_events_symbols_raw[] = {
32
};

static StaticExternalOneByteResource internal_events_symbols_resource(internal_events_symbols_raw, 1, nullptr);

static const uint8_t internal_file_raw[] = {
32
};

static StaticExternalOneByteResource internal_file_resource(internal_file_raw, 1, nullptr);

static const uint8_t internal_fixed_queue_raw[] = {
32
};

static StaticExternalOneByteResource internal_fixed_queue_resource(internal_fixed_queue_raw, 1, nullptr);

static const uint8_t internal_freelist_raw[] = {
32
};

static StaticExternalOneByteResource internal_freelist_resource(internal_freelist_raw, 1, nullptr);

static const uint8_t internal_freeze_intrinsics_raw[] = {
32
};

static StaticExternalOneByteResource internal_freeze_intrinsics_resource(internal_freeze_intrinsics_raw, 1, nullptr);

static const uint8_t internal_fs_cp_cp_sync_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_cp_cp_sync_resource(internal_fs_cp_cp_sync_raw, 1, nullptr);

static const uint8_t internal_fs_cp_cp_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_cp_cp_resource(internal_fs_cp_cp_raw, 1, nullptr);

static const uint8_t internal_fs_dir_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_dir_resource(internal_fs_dir_raw, 1, nullptr);

static const uint8_t internal_fs_glob_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_glob_resource(internal_fs_glob_raw, 1, nullptr);

static const uint8_t internal_fs_promises_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_promises_resource(internal_fs_promises_raw, 1, nullptr);

static const uint8_t internal_fs_read_context_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_read_context_resource(internal_fs_read_context_raw, 1, nullptr);

static const uint8_t internal_fs_recursive_watch_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_recursive_watch_resource(internal_fs_recursive_watch_raw, 1, nullptr);

static const uint8_t internal_fs_rimraf_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_rimraf_resource(internal_fs_rimraf_raw, 1, nullptr);

static const uint8_t internal_fs_streams_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_streams_resource(internal_fs_streams_raw, 1, nullptr);

static const uint8_t internal_fs_sync_write_stream_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_sync_write_stream_resource(internal_fs_sync_write_stream_raw, 1, nullptr);

static const uint8_t internal_fs_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_utils_resource(internal_fs_utils_raw, 1, nullptr);

static const uint8_t internal_fs_watchers_raw[] = {
32
};

static StaticExternalOneByteResource internal_fs_watchers_resource(internal_fs_watchers_raw, 1, nullptr);

static const uint8_t internal_heap_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_heap_utils_resource(internal_heap_utils_raw, 1, nullptr);

static const uint8_t internal_histogram_raw[] = {
32
};

static StaticExternalOneByteResource internal_histogram_resource(internal_histogram_raw, 1, nullptr);

static const uint8_t internal_http_raw[] = {
32
};

static StaticExternalOneByteResource internal_http_resource(internal_http_raw, 1, nullptr);

static const uint8_t internal_http2_compat_raw[] = {
32
};

static StaticExternalOneByteResource internal_http2_compat_resource(internal_http2_compat_raw, 1, nullptr);

static const uint8_t internal_http2_core_raw[] = {
32
};

static StaticExternalOneByteResource internal_http2_core_resource(internal_http2_core_raw, 1, nullptr);

static const uint8_t internal_http2_util_raw[] = {
32
};

static StaticExternalOneByteResource internal_http2_util_resource(internal_http2_util_raw, 1, nullptr);

static const uint8_t internal_inspector_network_raw[] = {
32
};

static StaticExternalOneByteResource internal_inspector_network_resource(internal_inspector_network_raw, 1, nullptr);

static const uint8_t internal_inspector_network_http_raw[] = {
32
};

static StaticExternalOneByteResource internal_inspector_network_http_resource(internal_inspector_network_http_raw, 1, nullptr);

static const uint8_t internal_inspector_network_undici_raw[] = {
32
};

static StaticExternalOneByteResource internal_inspector_network_undici_resource(internal_inspector_network_undici_raw, 1, nullptr);

static const uint8_t internal_inspector_async_hook_raw[] = {
32
};

static StaticExternalOneByteResource internal_inspector_async_hook_resource(internal_inspector_async_hook_raw, 1, nullptr);

static const uint8_t internal_inspector_network_tracking_raw[] = {
32
};

static StaticExternalOneByteResource internal_inspector_network_tracking_resource(internal_inspector_network_tracking_raw, 1, nullptr);

static const uint8_t internal_js_stream_socket_raw[] = {
32
};

static StaticExternalOneByteResource internal_js_stream_socket_resource(internal_js_stream_socket_raw, 1, nullptr);

static const uint8_t internal_legacy_processbinding_raw[] = {
32
};

static StaticExternalOneByteResource internal_legacy_processbinding_resource(internal_legacy_processbinding_raw, 1, nullptr);

static const uint8_t internal_linkedlist_raw[] = {
32
};

static StaticExternalOneByteResource internal_linkedlist_resource(internal_linkedlist_raw, 1, nullptr);

static const uint8_t internal_main_check_syntax_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_check_syntax_resource(internal_main_check_syntax_raw, 1, nullptr);

static const uint8_t internal_main_embedding_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_embedding_resource(internal_main_embedding_raw, 1, nullptr);

static const uint8_t internal_main_eval_stdin_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_eval_stdin_resource(internal_main_eval_stdin_raw, 1, nullptr);

static const uint8_t internal_main_eval_string_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_eval_string_resource(internal_main_eval_string_raw, 1, nullptr);

static const uint8_t internal_main_inspect_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_inspect_resource(internal_main_inspect_raw, 1, nullptr);

static const uint8_t internal_main_mksnapshot_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_mksnapshot_resource(internal_main_mksnapshot_raw, 1, nullptr);

static const uint8_t internal_main_print_help_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_print_help_resource(internal_main_print_help_raw, 1, nullptr);

static const uint8_t internal_main_prof_process_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_prof_process_resource(internal_main_prof_process_raw, 1, nullptr);

static const uint8_t internal_main_repl_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_repl_resource(internal_main_repl_raw, 1, nullptr);

static const uint8_t internal_main_run_main_module_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_run_main_module_resource(internal_main_run_main_module_raw, 1, nullptr);

static const uint8_t internal_main_test_runner_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_test_runner_resource(internal_main_test_runner_raw, 1, nullptr);

static const uint8_t internal_main_watch_mode_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_watch_mode_resource(internal_main_watch_mode_raw, 1, nullptr);

static const uint8_t internal_main_worker_thread_raw[] = {
32
};

static StaticExternalOneByteResource internal_main_worker_thread_resource(internal_main_worker_thread_raw, 1, nullptr);

static const uint8_t internal_mime_raw[] = {
32
};

static StaticExternalOneByteResource internal_mime_resource(internal_mime_raw, 1, nullptr);

static const uint8_t internal_modules_cjs_loader_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_cjs_loader_resource(internal_modules_cjs_loader_raw, 1, nullptr);

static const uint8_t internal_modules_customization_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_customization_hooks_resource(internal_modules_customization_hooks_raw, 1, nullptr);

static const uint8_t internal_modules_esm_assert_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_assert_resource(internal_modules_esm_assert_raw, 1, nullptr);

static const uint8_t internal_modules_esm_create_dynamic_module_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_create_dynamic_module_resource(internal_modules_esm_create_dynamic_module_raw, 1, nullptr);

static const uint8_t internal_modules_esm_formats_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_formats_resource(internal_modules_esm_formats_raw, 1, nullptr);

static const uint8_t internal_modules_esm_get_format_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_get_format_resource(internal_modules_esm_get_format_raw, 1, nullptr);

static const uint8_t internal_modules_esm_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_hooks_resource(internal_modules_esm_hooks_raw, 1, nullptr);

static const uint8_t internal_modules_esm_initialize_import_meta_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_initialize_import_meta_resource(internal_modules_esm_initialize_import_meta_raw, 1, nullptr);

static const uint8_t internal_modules_esm_load_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_load_resource(internal_modules_esm_load_raw, 1, nullptr);

static const uint8_t internal_modules_esm_loader_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_loader_resource(internal_modules_esm_loader_raw, 1, nullptr);

static const uint8_t internal_modules_esm_module_job_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_module_job_resource(internal_modules_esm_module_job_raw, 1, nullptr);

static const uint8_t internal_modules_esm_module_map_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_module_map_resource(internal_modules_esm_module_map_raw, 1, nullptr);

static const uint8_t internal_modules_esm_resolve_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_resolve_resource(internal_modules_esm_resolve_raw, 1, nullptr);

static const uint8_t internal_modules_esm_shared_constants_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_shared_constants_resource(internal_modules_esm_shared_constants_raw, 1, nullptr);

static const uint8_t internal_modules_esm_translators_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_translators_resource(internal_modules_esm_translators_raw, 1, nullptr);

static const uint8_t internal_modules_esm_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_utils_resource(internal_modules_esm_utils_raw, 1, nullptr);

static const uint8_t internal_modules_esm_worker_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_esm_worker_resource(internal_modules_esm_worker_raw, 1, nullptr);

static const uint8_t internal_modules_helpers_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_helpers_resource(internal_modules_helpers_raw, 1, nullptr);

static const uint8_t internal_modules_package_json_reader_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_package_json_reader_resource(internal_modules_package_json_reader_raw, 1, nullptr);

static const uint8_t internal_modules_run_main_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_run_main_resource(internal_modules_run_main_raw, 1, nullptr);

static const uint8_t internal_modules_typescript_raw[] = {
32
};

static StaticExternalOneByteResource internal_modules_typescript_resource(internal_modules_typescript_raw, 1, nullptr);

static const uint8_t internal_navigator_raw[] = {
32
};

static StaticExternalOneByteResource internal_navigator_resource(internal_navigator_raw, 1, nullptr);

static const uint8_t internal_net_raw[] = {
32
};

static StaticExternalOneByteResource internal_net_resource(internal_net_raw, 1, nullptr);

static const uint8_t internal_options_raw[] = {
32
};

static StaticExternalOneByteResource internal_options_resource(internal_options_raw, 1, nullptr);

static const uint8_t internal_per_context_domexception_raw[] = {
32
};

static StaticExternalOneByteResource internal_per_context_domexception_resource(internal_per_context_domexception_raw, 1, nullptr);

static const uint8_t internal_per_context_messageport_raw[] = {
32
};

static StaticExternalOneByteResource internal_per_context_messageport_resource(internal_per_context_messageport_raw, 1, nullptr);

static const uint8_t internal_per_context_primordials_raw[] = {
32
};

static StaticExternalOneByteResource internal_per_context_primordials_resource(internal_per_context_primordials_raw, 1, nullptr);

static const uint8_t internal_perf_event_loop_delay_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_event_loop_delay_resource(internal_perf_event_loop_delay_raw, 1, nullptr);

static const uint8_t internal_perf_event_loop_utilization_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_event_loop_utilization_resource(internal_perf_event_loop_utilization_raw, 1, nullptr);

static const uint8_t internal_perf_nodetiming_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_nodetiming_resource(internal_perf_nodetiming_raw, 1, nullptr);

static const uint8_t internal_perf_observe_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_observe_resource(internal_perf_observe_raw, 1, nullptr);

static const uint8_t internal_perf_performance_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_performance_resource(internal_perf_performance_raw, 1, nullptr);

static const uint8_t internal_perf_performance_entry_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_performance_entry_resource(internal_perf_performance_entry_raw, 1, nullptr);

static const uint8_t internal_perf_resource_timing_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_resource_timing_resource(internal_perf_resource_timing_raw, 1, nullptr);

static const uint8_t internal_perf_timerify_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_timerify_resource(internal_perf_timerify_raw, 1, nullptr);

static const uint8_t internal_perf_usertiming_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_usertiming_resource(internal_perf_usertiming_raw, 1, nullptr);

static const uint8_t internal_perf_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_perf_utils_resource(internal_perf_utils_raw, 1, nullptr);

static const uint8_t internal_priority_queue_raw[] = {
32
};

static StaticExternalOneByteResource internal_priority_queue_resource(internal_priority_queue_raw, 1, nullptr);

static const uint8_t internal_process_execution_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_execution_resource(internal_process_execution_raw, 1, nullptr);

static const uint8_t internal_process_finalization_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_finalization_resource(internal_process_finalization_raw, 1, nullptr);

static const uint8_t internal_process_per_thread_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_per_thread_resource(internal_process_per_thread_raw, 1, nullptr);

static const uint8_t internal_process_permission_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_permission_resource(internal_process_permission_raw, 1, nullptr);

static const uint8_t internal_process_pre_execution_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_pre_execution_resource(internal_process_pre_execution_raw, 1, nullptr);

static const uint8_t internal_process_promises_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_promises_resource(internal_process_promises_raw, 1, nullptr);

static const uint8_t internal_process_report_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_report_resource(internal_process_report_raw, 1, nullptr);

static const uint8_t internal_process_signal_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_signal_resource(internal_process_signal_raw, 1, nullptr);

static const uint8_t internal_process_task_queues_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_task_queues_resource(internal_process_task_queues_raw, 1, nullptr);

static const uint8_t internal_process_warning_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_warning_resource(internal_process_warning_raw, 1, nullptr);

static const uint8_t internal_process_worker_thread_only_raw[] = {
32
};

static StaticExternalOneByteResource internal_process_worker_thread_only_resource(internal_process_worker_thread_only_raw, 1, nullptr);

static const uint8_t internal_promise_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_promise_hooks_resource(internal_promise_hooks_raw, 1, nullptr);

static const uint8_t internal_querystring_raw[] = {
32
};

static StaticExternalOneByteResource internal_querystring_resource(internal_querystring_raw, 1, nullptr);

static const uint8_t internal_quic_quic_raw[] = {
32
};

static StaticExternalOneByteResource internal_quic_quic_resource(internal_quic_quic_raw, 1, nullptr);

static const uint8_t internal_quic_state_raw[] = {
32
};

static StaticExternalOneByteResource internal_quic_state_resource(internal_quic_state_raw, 1, nullptr);

static const uint8_t internal_quic_stats_raw[] = {
32
};

static StaticExternalOneByteResource internal_quic_stats_resource(internal_quic_stats_raw, 1, nullptr);

static const uint8_t internal_quic_symbols_raw[] = {
32
};

static StaticExternalOneByteResource internal_quic_symbols_resource(internal_quic_symbols_raw, 1, nullptr);

static const uint8_t internal_readline_callbacks_raw[] = {
32
};

static StaticExternalOneByteResource internal_readline_callbacks_resource(internal_readline_callbacks_raw, 1, nullptr);

static const uint8_t internal_readline_emitKeypressEvents_raw[] = {
32
};

static StaticExternalOneByteResource internal_readline_emitKeypressEvents_resource(internal_readline_emitKeypressEvents_raw, 1, nullptr);

static const uint8_t internal_readline_interface_raw[] = {
32
};

static StaticExternalOneByteResource internal_readline_interface_resource(internal_readline_interface_raw, 1, nullptr);

static const uint8_t internal_readline_promises_raw[] = {
32
};

static StaticExternalOneByteResource internal_readline_promises_resource(internal_readline_promises_raw, 1, nullptr);

static const uint8_t internal_readline_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_readline_utils_resource(internal_readline_utils_raw, 1, nullptr);

static const uint8_t internal_repl_raw[] = {
32
};

static StaticExternalOneByteResource internal_repl_resource(internal_repl_raw, 1, nullptr);

static const uint8_t internal_repl_await_raw[] = {
32
};

static StaticExternalOneByteResource internal_repl_await_resource(internal_repl_await_raw, 1, nullptr);

static const uint8_t internal_repl_history_raw[] = {
32
};

static StaticExternalOneByteResource internal_repl_history_resource(internal_repl_history_raw, 1, nullptr);

static const uint8_t internal_repl_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_repl_utils_resource(internal_repl_utils_raw, 1, nullptr);

static const uint8_t internal_socket_list_raw[] = {
32
};

static StaticExternalOneByteResource internal_socket_list_resource(internal_socket_list_raw, 1, nullptr);

static const uint8_t internal_socketaddress_raw[] = {
32
};

static StaticExternalOneByteResource internal_socketaddress_resource(internal_socketaddress_raw, 1, nullptr);

static const uint8_t internal_source_map_prepare_stack_trace_raw[] = {
32
};

static StaticExternalOneByteResource internal_source_map_prepare_stack_trace_resource(internal_source_map_prepare_stack_trace_raw, 1, nullptr);

static const uint8_t internal_source_map_source_map_raw[] = {
32
};

static StaticExternalOneByteResource internal_source_map_source_map_resource(internal_source_map_source_map_raw, 1, nullptr);

static const uint8_t internal_source_map_source_map_cache_raw[] = {
32
};

static StaticExternalOneByteResource internal_source_map_source_map_cache_resource(internal_source_map_source_map_cache_raw, 1, nullptr);

static const uint8_t internal_source_map_source_map_cache_map_raw[] = {
32
};

static StaticExternalOneByteResource internal_source_map_source_map_cache_map_resource(internal_source_map_source_map_cache_map_raw, 1, nullptr);

static const uint8_t internal_stream_base_commons_raw[] = {
32
};

static StaticExternalOneByteResource internal_stream_base_commons_resource(internal_stream_base_commons_raw, 1, nullptr);

static const uint8_t internal_streams_add_abort_signal_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_add_abort_signal_resource(internal_streams_add_abort_signal_raw, 1, nullptr);

static const uint8_t internal_streams_compose_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_compose_resource(internal_streams_compose_raw, 1, nullptr);

static const uint8_t internal_streams_destroy_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_destroy_resource(internal_streams_destroy_raw, 1, nullptr);

static const uint8_t internal_streams_duplex_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_duplex_resource(internal_streams_duplex_raw, 1, nullptr);

static const uint8_t internal_streams_duplexify_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_duplexify_resource(internal_streams_duplexify_raw, 1, nullptr);

static const uint8_t internal_streams_duplexpair_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_duplexpair_resource(internal_streams_duplexpair_raw, 1, nullptr);

static const uint8_t internal_streams_end_of_stream_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_end_of_stream_resource(internal_streams_end_of_stream_raw, 1, nullptr);

static const uint8_t internal_streams_from_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_from_resource(internal_streams_from_raw, 1, nullptr);

static const uint8_t internal_streams_lazy_transform_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_lazy_transform_resource(internal_streams_lazy_transform_raw, 1, nullptr);

static const uint8_t internal_streams_legacy_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_legacy_resource(internal_streams_legacy_raw, 1, nullptr);

static const uint8_t internal_streams_operators_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_operators_resource(internal_streams_operators_raw, 1, nullptr);

static const uint8_t internal_streams_passthrough_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_passthrough_resource(internal_streams_passthrough_raw, 1, nullptr);

static const uint8_t internal_streams_pipeline_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_pipeline_resource(internal_streams_pipeline_raw, 1, nullptr);

static const uint8_t internal_streams_readable_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_readable_resource(internal_streams_readable_raw, 1, nullptr);

static const uint8_t internal_streams_state_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_state_resource(internal_streams_state_raw, 1, nullptr);

static const uint8_t internal_streams_transform_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_transform_resource(internal_streams_transform_raw, 1, nullptr);

static const uint8_t internal_streams_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_utils_resource(internal_streams_utils_raw, 1, nullptr);

static const uint8_t internal_streams_writable_raw[] = {
32
};

static StaticExternalOneByteResource internal_streams_writable_resource(internal_streams_writable_raw, 1, nullptr);

static const uint8_t internal_test_binding_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_binding_resource(internal_test_binding_raw, 1, nullptr);

static const uint8_t internal_test_transfer_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_transfer_resource(internal_test_transfer_raw, 1, nullptr);

static const uint8_t internal_test_runner_assert_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_assert_resource(internal_test_runner_assert_raw, 1, nullptr);

static const uint8_t internal_test_runner_coverage_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_coverage_resource(internal_test_runner_coverage_raw, 1, nullptr);

static const uint8_t internal_test_runner_harness_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_harness_resource(internal_test_runner_harness_raw, 1, nullptr);

static const uint8_t internal_test_runner_mock_loader_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_mock_loader_resource(internal_test_runner_mock_loader_raw, 1, nullptr);

static const uint8_t internal_test_runner_mock_mock_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_mock_mock_resource(internal_test_runner_mock_mock_raw, 1, nullptr);

static const uint8_t internal_test_runner_mock_mock_timers_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_mock_mock_timers_resource(internal_test_runner_mock_mock_timers_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_dot_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_dot_resource(internal_test_runner_reporter_dot_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_junit_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_junit_resource(internal_test_runner_reporter_junit_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_lcov_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_lcov_resource(internal_test_runner_reporter_lcov_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_spec_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_spec_resource(internal_test_runner_reporter_spec_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_tap_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_tap_resource(internal_test_runner_reporter_tap_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_utils_resource(internal_test_runner_reporter_utils_raw, 1, nullptr);

static const uint8_t internal_test_runner_reporter_v8_serializer_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_reporter_v8_serializer_resource(internal_test_runner_reporter_v8_serializer_raw, 1, nullptr);

static const uint8_t internal_test_runner_runner_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_runner_resource(internal_test_runner_runner_raw, 1, nullptr);

static const uint8_t internal_test_runner_snapshot_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_snapshot_resource(internal_test_runner_snapshot_raw, 1, nullptr);

static const uint8_t internal_test_runner_test_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_test_resource(internal_test_runner_test_raw, 1, nullptr);

static const uint8_t internal_test_runner_tests_stream_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_tests_stream_resource(internal_test_runner_tests_stream_raw, 1, nullptr);

static const uint8_t internal_test_runner_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_test_runner_utils_resource(internal_test_runner_utils_raw, 1, nullptr);

static const uint16_t internal_timers_raw[] = {
32
};

static StaticExternalTwoByteResource internal_timers_resource(internal_timers_raw, 1, nullptr);

static const uint8_t internal_tls_secure_context_raw[] = {
32
};

static StaticExternalOneByteResource internal_tls_secure_context_resource(internal_tls_secure_context_raw, 1, nullptr);

static const uint8_t internal_trace_events_async_hooks_raw[] = {
32
};

static StaticExternalOneByteResource internal_trace_events_async_hooks_resource(internal_trace_events_async_hooks_raw, 1, nullptr);

static const uint8_t internal_tty_raw[] = {
32
};

static StaticExternalOneByteResource internal_tty_resource(internal_tty_raw, 1, nullptr);

static const uint8_t internal_url_raw[] = {
32
};

static StaticExternalOneByteResource internal_url_resource(internal_url_raw, 1, nullptr);

static const uint8_t internal_util_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_resource(internal_util_raw, 1, nullptr);

static const uint8_t internal_util_colors_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_colors_resource(internal_util_colors_raw, 1, nullptr);

static const uint8_t internal_util_comparisons_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_comparisons_resource(internal_util_comparisons_raw, 1, nullptr);

static const uint8_t internal_util_debuglog_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_debuglog_resource(internal_util_debuglog_raw, 1, nullptr);

static const uint8_t internal_util_diff_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_diff_resource(internal_util_diff_raw, 1, nullptr);

static const uint8_t internal_util_inspect_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_inspect_resource(internal_util_inspect_raw, 1, nullptr);

static const uint8_t internal_util_inspector_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_inspector_resource(internal_util_inspector_raw, 1, nullptr);

static const uint8_t internal_util_parse_args_parse_args_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_parse_args_parse_args_resource(internal_util_parse_args_parse_args_raw, 1, nullptr);

static const uint8_t internal_util_parse_args_utils_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_parse_args_utils_resource(internal_util_parse_args_utils_raw, 1, nullptr);

static const uint8_t internal_util_types_raw[] = {
32
};

static StaticExternalOneByteResource internal_util_types_resource(internal_util_types_raw, 1, nullptr);

static const uint8_t internal_v8_startup_snapshot_raw[] = {
32
};

static StaticExternalOneByteResource internal_v8_startup_snapshot_resource(internal_v8_startup_snapshot_raw, 1, nullptr);

static const uint8_t internal_v8_prof_polyfill_raw[] = {
32
};

static StaticExternalOneByteResource internal_v8_prof_polyfill_resource(internal_v8_prof_polyfill_raw, 1, nullptr);

static const uint8_t internal_v8_prof_processor_raw[] = {
32
};

static StaticExternalOneByteResource internal_v8_prof_processor_resource(internal_v8_prof_processor_raw, 1, nullptr);

static const uint8_t internal_validators_raw[] = {
32
};

static StaticExternalOneByteResource internal_validators_resource(internal_validators_raw, 1, nullptr);

static const uint8_t internal_vm_raw[] = {
32
};

static StaticExternalOneByteResource internal_vm_resource(internal_vm_raw, 1, nullptr);

static const uint8_t internal_vm_module_raw[] = {
32
};

static StaticExternalOneByteResource internal_vm_module_resource(internal_vm_module_raw, 1, nullptr);

static const uint8_t internal_wasm_web_api_raw[] = {
32
};

static StaticExternalOneByteResource internal_wasm_web_api_resource(internal_wasm_web_api_raw, 1, nullptr);

static const uint8_t internal_watch_mode_files_watcher_raw[] = {
32
};

static StaticExternalOneByteResource internal_watch_mode_files_watcher_resource(internal_watch_mode_files_watcher_raw, 1, nullptr);

static const uint8_t internal_watchdog_raw[] = {
32
};

static StaticExternalOneByteResource internal_watchdog_resource(internal_watchdog_raw, 1, nullptr);

static const uint16_t internal_webidl_raw[] = {
32
};

static StaticExternalTwoByteResource internal_webidl_resource(internal_webidl_raw, 1, nullptr);

static const uint8_t internal_webstorage_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstorage_resource(internal_webstorage_raw, 1, nullptr);

static const uint8_t internal_webstreams_adapters_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_adapters_resource(internal_webstreams_adapters_raw, 1, nullptr);

static const uint8_t internal_webstreams_compression_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_compression_resource(internal_webstreams_compression_raw, 1, nullptr);

static const uint8_t internal_webstreams_encoding_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_encoding_resource(internal_webstreams_encoding_raw, 1, nullptr);

static const uint8_t internal_webstreams_queuingstrategies_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_queuingstrategies_resource(internal_webstreams_queuingstrategies_raw, 1, nullptr);

static const uint8_t internal_webstreams_readablestream_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_readablestream_resource(internal_webstreams_readablestream_raw, 1, nullptr);

static const uint8_t internal_webstreams_transfer_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_transfer_resource(internal_webstreams_transfer_raw, 1, nullptr);

static const uint8_t internal_webstreams_transformstream_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_transformstream_resource(internal_webstreams_transformstream_raw, 1, nullptr);

static const uint8_t internal_webstreams_util_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_util_resource(internal_webstreams_util_raw, 1, nullptr);

static const uint8_t internal_webstreams_writablestream_raw[] = {
32
};

static StaticExternalOneByteResource internal_webstreams_writablestream_resource(internal_webstreams_writablestream_raw, 1, nullptr);

static const uint8_t internal_worker_raw[] = {
32
};

static StaticExternalOneByteResource internal_worker_resource(internal_worker_raw, 1, nullptr);

static const uint8_t internal_worker_io_raw[] = {
32
};

static StaticExternalOneByteResource internal_worker_io_resource(internal_worker_io_raw, 1, nullptr);

static const uint8_t internal_worker_js_transferable_raw[] = {
32
};

static StaticExternalOneByteResource internal_worker_js_transferable_resource(internal_worker_js_transferable_raw, 1, nullptr);

static const uint8_t internal_worker_messaging_raw[] = {
32
};

static StaticExternalOneByteResource internal_worker_messaging_resource(internal_worker_messaging_raw, 1, nullptr);

static const uint8_t module_raw[] = {
32
};

static StaticExternalOneByteResource module_resource(module_raw, 1, nullptr);

static const uint8_t net_raw[] = {
32
};

static StaticExternalOneByteResource net_resource(net_raw, 1, nullptr);

static const uint8_t os_raw[] = {
32
};

static StaticExternalOneByteResource os_resource(os_raw, 1, nullptr);

static const uint8_t path_raw[] = {
32
};

static StaticExternalOneByteResource path_resource(path_raw, 1, nullptr);

static const uint8_t path_posix_raw[] = {
32
};

static StaticExternalOneByteResource path_posix_resource(path_posix_raw, 1, nullptr);

static const uint8_t path_win32_raw[] = {
32
};

static StaticExternalOneByteResource path_win32_resource(path_win32_raw, 1, nullptr);

static const uint8_t perf_hooks_raw[] = {
32
};

static StaticExternalOneByteResource perf_hooks_resource(perf_hooks_raw, 1, nullptr);

static const uint8_t process_raw[] = {
32
};

static StaticExternalOneByteResource process_resource(process_raw, 1, nullptr);

static const uint8_t punycode_raw[] = {
32
};

static StaticExternalOneByteResource punycode_resource(punycode_raw, 1, nullptr);

static const uint8_t querystring_raw[] = {
32
};

static StaticExternalOneByteResource querystring_resource(querystring_raw, 1, nullptr);

static const uint8_t quic_raw[] = {
32
};

static StaticExternalOneByteResource quic_resource(quic_raw, 1, nullptr);

static const uint8_t readline_raw[] = {
32
};

static StaticExternalOneByteResource readline_resource(readline_raw, 1, nullptr);

static const uint8_t readline_promises_raw[] = {
32
};

static StaticExternalOneByteResource readline_promises_resource(readline_promises_raw, 1, nullptr);

static const uint8_t repl_raw[] = {
32
};

static StaticExternalOneByteResource repl_resource(repl_raw, 1, nullptr);

static const uint8_t sea_raw[] = {
32
};

static StaticExternalOneByteResource sea_resource(sea_raw, 1, nullptr);

static const uint8_t sqlite_raw[] = {
32
};

static StaticExternalOneByteResource sqlite_resource(sqlite_raw, 1, nullptr);

static const uint8_t stream_raw[] = {
32
};

static StaticExternalOneByteResource stream_resource(stream_raw, 1, nullptr);

static const uint8_t stream_consumers_raw[] = {
32
};

static StaticExternalOneByteResource stream_consumers_resource(stream_consumers_raw, 1, nullptr);

static const uint8_t stream_promises_raw[] = {
32
};

static StaticExternalOneByteResource stream_promises_resource(stream_promises_raw, 1, nullptr);

static const uint8_t stream_web_raw[] = {
32
};

static StaticExternalOneByteResource stream_web_resource(stream_web_raw, 1, nullptr);

static const uint8_t string_decoder_raw[] = {
32
};

static StaticExternalOneByteResource string_decoder_resource(string_decoder_raw, 1, nullptr);

static const uint8_t sys_raw[] = {
32
};

static StaticExternalOneByteResource sys_resource(sys_raw, 1, nullptr);

static const uint8_t test_raw[] = {
32
};

static StaticExternalOneByteResource test_resource(test_raw, 1, nullptr);

static const uint8_t test_reporters_raw[] = {
32
};

static StaticExternalOneByteResource test_reporters_resource(test_reporters_raw, 1, nullptr);

static const uint8_t timers_raw[] = {
32
};

static StaticExternalOneByteResource timers_resource(timers_raw, 1, nullptr);

static const uint8_t timers_promises_raw[] = {
32
};

static StaticExternalOneByteResource timers_promises_resource(timers_promises_raw, 1, nullptr);

static const uint8_t tls_raw[] = {
32
};

static StaticExternalOneByteResource tls_resource(tls_raw, 1, nullptr);

static const uint8_t trace_events_raw[] = {
32
};

static StaticExternalOneByteResource trace_events_resource(trace_events_raw, 1, nullptr);

static const uint8_t tty_raw[] = {
32
};

static StaticExternalOneByteResource tty_resource(tty_raw, 1, nullptr);

static const uint8_t url_raw[] = {
32
};

static StaticExternalOneByteResource url_resource(url_raw, 1, nullptr);

static const uint8_t util_raw[] = {
32
};

static StaticExternalOneByteResource util_resource(util_raw, 1, nullptr);

static const uint8_t util_types_raw[] = {
32
};

static StaticExternalOneByteResource util_types_resource(util_types_raw, 1, nullptr);

static const uint8_t v8_raw[] = {
32
};

static StaticExternalOneByteResource v8_resource(v8_raw, 1, nullptr);

static const uint8_t vm_raw[] = {
32
};

static StaticExternalOneByteResource vm_resource(vm_raw, 1, nullptr);

static const uint8_t wasi_raw[] = {
32
};

static StaticExternalOneByteResource wasi_resource(wasi_raw, 1, nullptr);

static const uint8_t worker_threads_raw[] = {
32
};

static StaticExternalOneByteResource worker_threads_resource(worker_threads_raw, 1, nullptr);

static const uint8_t zlib_raw[] = {
32
};

static StaticExternalOneByteResource zlib_resource(zlib_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_arguments_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_arguments_resource(internal_deps_v8_tools_arguments_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_codemap_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_codemap_resource(internal_deps_v8_tools_codemap_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_consarray_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_consarray_resource(internal_deps_v8_tools_consarray_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_csvparser_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_csvparser_resource(internal_deps_v8_tools_csvparser_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_logreader_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_logreader_resource(internal_deps_v8_tools_logreader_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_profile_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_profile_resource(internal_deps_v8_tools_profile_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_profile_view_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_profile_view_resource(internal_deps_v8_tools_profile_view_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_sourcemap_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_sourcemap_resource(internal_deps_v8_tools_sourcemap_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_splaytree_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_splaytree_resource(internal_deps_v8_tools_splaytree_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_tickprocessor_driver_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_tickprocessor_driver_resource(internal_deps_v8_tools_tickprocessor_driver_raw, 1, nullptr);

static const uint8_t internal_deps_v8_tools_tickprocessor_raw[] = {
32
};

static StaticExternalOneByteResource internal_deps_v8_tools_tickprocessor_resource(internal_deps_v8_tools_tickprocessor_raw, 1, nullptr);

static const uint8_t config_raw[] = {
32
};

static StaticExternalOneByteResource config_resource(config_raw, 1, nullptr);

namespace {
const ThreadsafeCopyOnWrite<BuiltinSourceMap> global_source_map {
  BuiltinSourceMap {
    {"internal/deps/acorn/acorn-walk/dist/walk", UnionBytes(&internal_deps_acorn_acorn_walk_dist_walk_resource) },
    {"internal/deps/acorn/acorn/dist/acorn", UnionBytes(&internal_deps_acorn_acorn_dist_acorn_resource) },
    {"internal/deps/amaro/dist/index", UnionBytes(&internal_deps_amaro_dist_index_resource) },
    {"internal/deps/cjs-module-lexer/dist/lexer", UnionBytes(&internal_deps_cjs_module_lexer_dist_lexer_resource) },
    {"internal/deps/cjs-module-lexer/lexer", UnionBytes(&internal_deps_cjs_module_lexer_lexer_resource) },
    {"internal/deps/minimatch/index", UnionBytes(&internal_deps_minimatch_index_resource) },
    {"internal/deps/undici/undici", UnionBytes(&internal_deps_undici_undici_resource) },
    {"_http_agent", UnionBytes(&_http_agent_resource) },
    {"_http_client", UnionBytes(&_http_client_resource) },
    {"_http_common", UnionBytes(&_http_common_resource) },
    {"_http_incoming", UnionBytes(&_http_incoming_resource) },
    {"_http_outgoing", UnionBytes(&_http_outgoing_resource) },
    {"_http_server", UnionBytes(&_http_server_resource) },
    {"_stream_duplex", UnionBytes(&_stream_duplex_resource) },
    {"_stream_passthrough", UnionBytes(&_stream_passthrough_resource) },
    {"_stream_readable", UnionBytes(&_stream_readable_resource) },
    {"_stream_transform", UnionBytes(&_stream_transform_resource) },
    {"_stream_wrap", UnionBytes(&_stream_wrap_resource) },
    {"_stream_writable", UnionBytes(&_stream_writable_resource) },
    {"_tls_common", UnionBytes(&_tls_common_resource) },
    {"_tls_wrap", UnionBytes(&_tls_wrap_resource) },
    {"assert", UnionBytes(&assert_resource) },
    {"assert/strict", UnionBytes(&assert_strict_resource) },
    {"async_hooks", UnionBytes(&async_hooks_resource) },
    {"buffer", UnionBytes(&buffer_resource) },
    {"child_process", UnionBytes(&child_process_resource) },
    {"cluster", UnionBytes(&cluster_resource) },
    {"console", UnionBytes(&console_resource) },
    {"constants", UnionBytes(&constants_resource) },
    {"crypto", UnionBytes(&crypto_resource) },
    {"dgram", UnionBytes(&dgram_resource) },
    {"diagnostics_channel", UnionBytes(&diagnostics_channel_resource) },
    {"dns", UnionBytes(&dns_resource) },
    {"dns/promises", UnionBytes(&dns_promises_resource) },
    {"domain", UnionBytes(&domain_resource) },
    {"events", UnionBytes(&events_resource) },
    {"fs", UnionBytes(&fs_resource) },
    {"fs/promises", UnionBytes(&fs_promises_resource) },
    {"http", UnionBytes(&http_resource) },
    {"http2", UnionBytes(&http2_resource) },
    {"https", UnionBytes(&https_resource) },
    {"inspector", UnionBytes(&inspector_resource) },
    {"inspector/promises", UnionBytes(&inspector_promises_resource) },
    {"internal/abort_controller", UnionBytes(&internal_abort_controller_resource) },
    {"internal/assert", UnionBytes(&internal_assert_resource) },
    {"internal/assert/assertion_error", UnionBytes(&internal_assert_assertion_error_resource) },
    {"internal/assert/calltracker", UnionBytes(&internal_assert_calltracker_resource) },
    {"internal/assert/myers_diff", UnionBytes(&internal_assert_myers_diff_resource) },
    {"internal/assert/utils", UnionBytes(&internal_assert_utils_resource) },
    {"internal/async_context_frame", UnionBytes(&internal_async_context_frame_resource) },
    {"internal/async_hooks", UnionBytes(&internal_async_hooks_resource) },
    {"internal/async_local_storage/async_context_frame", UnionBytes(&internal_async_local_storage_async_context_frame_resource) },
    {"internal/async_local_storage/async_hooks", UnionBytes(&internal_async_local_storage_async_hooks_resource) },
    {"internal/blob", UnionBytes(&internal_blob_resource) },
    {"internal/blocklist", UnionBytes(&internal_blocklist_resource) },
    {"internal/bootstrap/node", UnionBytes(&internal_bootstrap_node_resource) },
    {"internal/bootstrap/realm", UnionBytes(&internal_bootstrap_realm_resource) },
    {"internal/bootstrap/shadow_realm", UnionBytes(&internal_bootstrap_shadow_realm_resource) },
    {"internal/bootstrap/switches/does_not_own_process_state", UnionBytes(&internal_bootstrap_switches_does_not_own_process_state_resource) },
    {"internal/bootstrap/switches/does_own_process_state", UnionBytes(&internal_bootstrap_switches_does_own_process_state_resource) },
    {"internal/bootstrap/switches/is_main_thread", UnionBytes(&internal_bootstrap_switches_is_main_thread_resource) },
    {"internal/bootstrap/switches/is_not_main_thread", UnionBytes(&internal_bootstrap_switches_is_not_main_thread_resource) },
    {"internal/bootstrap/web/exposed-wildcard", UnionBytes(&internal_bootstrap_web_exposed_wildcard_resource) },
    {"internal/bootstrap/web/exposed-window-or-worker", UnionBytes(&internal_bootstrap_web_exposed_window_or_worker_resource) },
    {"internal/buffer", UnionBytes(&internal_buffer_resource) },
    {"internal/child_process", UnionBytes(&internal_child_process_resource) },
    {"internal/child_process/serialization", UnionBytes(&internal_child_process_serialization_resource) },
    {"internal/cli_table", UnionBytes(&internal_cli_table_resource) },
    {"internal/cluster/child", UnionBytes(&internal_cluster_child_resource) },
    {"internal/cluster/primary", UnionBytes(&internal_cluster_primary_resource) },
    {"internal/cluster/round_robin_handle", UnionBytes(&internal_cluster_round_robin_handle_resource) },
    {"internal/cluster/shared_handle", UnionBytes(&internal_cluster_shared_handle_resource) },
    {"internal/cluster/utils", UnionBytes(&internal_cluster_utils_resource) },
    {"internal/cluster/worker", UnionBytes(&internal_cluster_worker_resource) },
    {"internal/console/constructor", UnionBytes(&internal_console_constructor_resource) },
    {"internal/console/global", UnionBytes(&internal_console_global_resource) },
    {"internal/constants", UnionBytes(&internal_constants_resource) },
    {"internal/crypto/aes", UnionBytes(&internal_crypto_aes_resource) },
    {"internal/crypto/certificate", UnionBytes(&internal_crypto_certificate_resource) },
    {"internal/crypto/cfrg", UnionBytes(&internal_crypto_cfrg_resource) },
    {"internal/crypto/cipher", UnionBytes(&internal_crypto_cipher_resource) },
    {"internal/crypto/diffiehellman", UnionBytes(&internal_crypto_diffiehellman_resource) },
    {"internal/crypto/ec", UnionBytes(&internal_crypto_ec_resource) },
    {"internal/crypto/hash", UnionBytes(&internal_crypto_hash_resource) },
    {"internal/crypto/hashnames", UnionBytes(&internal_crypto_hashnames_resource) },
    {"internal/crypto/hkdf", UnionBytes(&internal_crypto_hkdf_resource) },
    {"internal/crypto/keygen", UnionBytes(&internal_crypto_keygen_resource) },
    {"internal/crypto/keys", UnionBytes(&internal_crypto_keys_resource) },
    {"internal/crypto/mac", UnionBytes(&internal_crypto_mac_resource) },
    {"internal/crypto/pbkdf2", UnionBytes(&internal_crypto_pbkdf2_resource) },
    {"internal/crypto/random", UnionBytes(&internal_crypto_random_resource) },
    {"internal/crypto/rsa", UnionBytes(&internal_crypto_rsa_resource) },
    {"internal/crypto/scrypt", UnionBytes(&internal_crypto_scrypt_resource) },
    {"internal/crypto/sig", UnionBytes(&internal_crypto_sig_resource) },
    {"internal/crypto/util", UnionBytes(&internal_crypto_util_resource) },
    {"internal/crypto/webcrypto", UnionBytes(&internal_crypto_webcrypto_resource) },
    {"internal/crypto/webidl", UnionBytes(&internal_crypto_webidl_resource) },
    {"internal/crypto/x509", UnionBytes(&internal_crypto_x509_resource) },
    {"internal/data_url", UnionBytes(&internal_data_url_resource) },
    {"internal/debugger/inspect", UnionBytes(&internal_debugger_inspect_resource) },
    {"internal/debugger/inspect_client", UnionBytes(&internal_debugger_inspect_client_resource) },
    {"internal/debugger/inspect_repl", UnionBytes(&internal_debugger_inspect_repl_resource) },
    {"internal/dgram", UnionBytes(&internal_dgram_resource) },
    {"internal/dns/callback_resolver", UnionBytes(&internal_dns_callback_resolver_resource) },
    {"internal/dns/promises", UnionBytes(&internal_dns_promises_resource) },
    {"internal/dns/utils", UnionBytes(&internal_dns_utils_resource) },
    {"internal/encoding", UnionBytes(&internal_encoding_resource) },
    {"internal/error_serdes", UnionBytes(&internal_error_serdes_resource) },
    {"internal/errors", UnionBytes(&internal_errors_resource) },
    {"internal/event_target", UnionBytes(&internal_event_target_resource) },
    {"internal/events/abort_listener", UnionBytes(&internal_events_abort_listener_resource) },
    {"internal/events/symbols", UnionBytes(&internal_events_symbols_resource) },
    {"internal/file", UnionBytes(&internal_file_resource) },
    {"internal/fixed_queue", UnionBytes(&internal_fixed_queue_resource) },
    {"internal/freelist", UnionBytes(&internal_freelist_resource) },
    {"internal/freeze_intrinsics", UnionBytes(&internal_freeze_intrinsics_resource) },
    {"internal/fs/cp/cp-sync", UnionBytes(&internal_fs_cp_cp_sync_resource) },
    {"internal/fs/cp/cp", UnionBytes(&internal_fs_cp_cp_resource) },
    {"internal/fs/dir", UnionBytes(&internal_fs_dir_resource) },
    {"internal/fs/glob", UnionBytes(&internal_fs_glob_resource) },
    {"internal/fs/promises", UnionBytes(&internal_fs_promises_resource) },
    {"internal/fs/read/context", UnionBytes(&internal_fs_read_context_resource) },
    {"internal/fs/recursive_watch", UnionBytes(&internal_fs_recursive_watch_resource) },
    {"internal/fs/rimraf", UnionBytes(&internal_fs_rimraf_resource) },
    {"internal/fs/streams", UnionBytes(&internal_fs_streams_resource) },
    {"internal/fs/sync_write_stream", UnionBytes(&internal_fs_sync_write_stream_resource) },
    {"internal/fs/utils", UnionBytes(&internal_fs_utils_resource) },
    {"internal/fs/watchers", UnionBytes(&internal_fs_watchers_resource) },
    {"internal/heap_utils", UnionBytes(&internal_heap_utils_resource) },
    {"internal/histogram", UnionBytes(&internal_histogram_resource) },
    {"internal/http", UnionBytes(&internal_http_resource) },
    {"internal/http2/compat", UnionBytes(&internal_http2_compat_resource) },
    {"internal/http2/core", UnionBytes(&internal_http2_core_resource) },
    {"internal/http2/util", UnionBytes(&internal_http2_util_resource) },
    {"internal/inspector/network", UnionBytes(&internal_inspector_network_resource) },
    {"internal/inspector/network_http", UnionBytes(&internal_inspector_network_http_resource) },
    {"internal/inspector/network_undici", UnionBytes(&internal_inspector_network_undici_resource) },
    {"internal/inspector_async_hook", UnionBytes(&internal_inspector_async_hook_resource) },
    {"internal/inspector_network_tracking", UnionBytes(&internal_inspector_network_tracking_resource) },
    {"internal/js_stream_socket", UnionBytes(&internal_js_stream_socket_resource) },
    {"internal/legacy/processbinding", UnionBytes(&internal_legacy_processbinding_resource) },
    {"internal/linkedlist", UnionBytes(&internal_linkedlist_resource) },
    {"internal/main/check_syntax", UnionBytes(&internal_main_check_syntax_resource) },
    {"internal/main/embedding", UnionBytes(&internal_main_embedding_resource) },
    {"internal/main/eval_stdin", UnionBytes(&internal_main_eval_stdin_resource) },
    {"internal/main/eval_string", UnionBytes(&internal_main_eval_string_resource) },
    {"internal/main/inspect", UnionBytes(&internal_main_inspect_resource) },
    {"internal/main/mksnapshot", UnionBytes(&internal_main_mksnapshot_resource) },
    {"internal/main/print_help", UnionBytes(&internal_main_print_help_resource) },
    {"internal/main/prof_process", UnionBytes(&internal_main_prof_process_resource) },
    {"internal/main/repl", UnionBytes(&internal_main_repl_resource) },
    {"internal/main/run_main_module", UnionBytes(&internal_main_run_main_module_resource) },
    {"internal/main/test_runner", UnionBytes(&internal_main_test_runner_resource) },
    {"internal/main/watch_mode", UnionBytes(&internal_main_watch_mode_resource) },
    {"internal/main/worker_thread", UnionBytes(&internal_main_worker_thread_resource) },
    {"internal/mime", UnionBytes(&internal_mime_resource) },
    {"internal/modules/cjs/loader", UnionBytes(&internal_modules_cjs_loader_resource) },
    {"internal/modules/customization_hooks", UnionBytes(&internal_modules_customization_hooks_resource) },
    {"internal/modules/esm/assert", UnionBytes(&internal_modules_esm_assert_resource) },
    {"internal/modules/esm/create_dynamic_module", UnionBytes(&internal_modules_esm_create_dynamic_module_resource) },
    {"internal/modules/esm/formats", UnionBytes(&internal_modules_esm_formats_resource) },
    {"internal/modules/esm/get_format", UnionBytes(&internal_modules_esm_get_format_resource) },
    {"internal/modules/esm/hooks", UnionBytes(&internal_modules_esm_hooks_resource) },
    {"internal/modules/esm/initialize_import_meta", UnionBytes(&internal_modules_esm_initialize_import_meta_resource) },
    {"internal/modules/esm/load", UnionBytes(&internal_modules_esm_load_resource) },
    {"internal/modules/esm/loader", UnionBytes(&internal_modules_esm_loader_resource) },
    {"internal/modules/esm/module_job", UnionBytes(&internal_modules_esm_module_job_resource) },
    {"internal/modules/esm/module_map", UnionBytes(&internal_modules_esm_module_map_resource) },
    {"internal/modules/esm/resolve", UnionBytes(&internal_modules_esm_resolve_resource) },
    {"internal/modules/esm/shared_constants", UnionBytes(&internal_modules_esm_shared_constants_resource) },
    {"internal/modules/esm/translators", UnionBytes(&internal_modules_esm_translators_resource) },
    {"internal/modules/esm/utils", UnionBytes(&internal_modules_esm_utils_resource) },
    {"internal/modules/esm/worker", UnionBytes(&internal_modules_esm_worker_resource) },
    {"internal/modules/helpers", UnionBytes(&internal_modules_helpers_resource) },
    {"internal/modules/package_json_reader", UnionBytes(&internal_modules_package_json_reader_resource) },
    {"internal/modules/run_main", UnionBytes(&internal_modules_run_main_resource) },
    {"internal/modules/typescript", UnionBytes(&internal_modules_typescript_resource) },
    {"internal/navigator", UnionBytes(&internal_navigator_resource) },
    {"internal/net", UnionBytes(&internal_net_resource) },
    {"internal/options", UnionBytes(&internal_options_resource) },
    {"internal/per_context/domexception", UnionBytes(&internal_per_context_domexception_resource) },
    {"internal/per_context/messageport", UnionBytes(&internal_per_context_messageport_resource) },
    {"internal/per_context/primordials", UnionBytes(&internal_per_context_primordials_resource) },
    {"internal/perf/event_loop_delay", UnionBytes(&internal_perf_event_loop_delay_resource) },
    {"internal/perf/event_loop_utilization", UnionBytes(&internal_perf_event_loop_utilization_resource) },
    {"internal/perf/nodetiming", UnionBytes(&internal_perf_nodetiming_resource) },
    {"internal/perf/observe", UnionBytes(&internal_perf_observe_resource) },
    {"internal/perf/performance", UnionBytes(&internal_perf_performance_resource) },
    {"internal/perf/performance_entry", UnionBytes(&internal_perf_performance_entry_resource) },
    {"internal/perf/resource_timing", UnionBytes(&internal_perf_resource_timing_resource) },
    {"internal/perf/timerify", UnionBytes(&internal_perf_timerify_resource) },
    {"internal/perf/usertiming", UnionBytes(&internal_perf_usertiming_resource) },
    {"internal/perf/utils", UnionBytes(&internal_perf_utils_resource) },
    {"internal/priority_queue", UnionBytes(&internal_priority_queue_resource) },
    {"internal/process/execution", UnionBytes(&internal_process_execution_resource) },
    {"internal/process/finalization", UnionBytes(&internal_process_finalization_resource) },
    {"internal/process/per_thread", UnionBytes(&internal_process_per_thread_resource) },
    {"internal/process/permission", UnionBytes(&internal_process_permission_resource) },
    {"internal/process/pre_execution", UnionBytes(&internal_process_pre_execution_resource) },
    {"internal/process/promises", UnionBytes(&internal_process_promises_resource) },
    {"internal/process/report", UnionBytes(&internal_process_report_resource) },
    {"internal/process/signal", UnionBytes(&internal_process_signal_resource) },
    {"internal/process/task_queues", UnionBytes(&internal_process_task_queues_resource) },
    {"internal/process/warning", UnionBytes(&internal_process_warning_resource) },
    {"internal/process/worker_thread_only", UnionBytes(&internal_process_worker_thread_only_resource) },
    {"internal/promise_hooks", UnionBytes(&internal_promise_hooks_resource) },
    {"internal/querystring", UnionBytes(&internal_querystring_resource) },
    {"internal/quic/quic", UnionBytes(&internal_quic_quic_resource) },
    {"internal/quic/state", UnionBytes(&internal_quic_state_resource) },
    {"internal/quic/stats", UnionBytes(&internal_quic_stats_resource) },
    {"internal/quic/symbols", UnionBytes(&internal_quic_symbols_resource) },
    {"internal/readline/callbacks", UnionBytes(&internal_readline_callbacks_resource) },
    {"internal/readline/emitKeypressEvents", UnionBytes(&internal_readline_emitKeypressEvents_resource) },
    {"internal/readline/interface", UnionBytes(&internal_readline_interface_resource) },
    {"internal/readline/promises", UnionBytes(&internal_readline_promises_resource) },
    {"internal/readline/utils", UnionBytes(&internal_readline_utils_resource) },
    {"internal/repl", UnionBytes(&internal_repl_resource) },
    {"internal/repl/await", UnionBytes(&internal_repl_await_resource) },
    {"internal/repl/history", UnionBytes(&internal_repl_history_resource) },
    {"internal/repl/utils", UnionBytes(&internal_repl_utils_resource) },
    {"internal/socket_list", UnionBytes(&internal_socket_list_resource) },
    {"internal/socketaddress", UnionBytes(&internal_socketaddress_resource) },
    {"internal/source_map/prepare_stack_trace", UnionBytes(&internal_source_map_prepare_stack_trace_resource) },
    {"internal/source_map/source_map", UnionBytes(&internal_source_map_source_map_resource) },
    {"internal/source_map/source_map_cache", UnionBytes(&internal_source_map_source_map_cache_resource) },
    {"internal/source_map/source_map_cache_map", UnionBytes(&internal_source_map_source_map_cache_map_resource) },
    {"internal/stream_base_commons", UnionBytes(&internal_stream_base_commons_resource) },
    {"internal/streams/add-abort-signal", UnionBytes(&internal_streams_add_abort_signal_resource) },
    {"internal/streams/compose", UnionBytes(&internal_streams_compose_resource) },
    {"internal/streams/destroy", UnionBytes(&internal_streams_destroy_resource) },
    {"internal/streams/duplex", UnionBytes(&internal_streams_duplex_resource) },
    {"internal/streams/duplexify", UnionBytes(&internal_streams_duplexify_resource) },
    {"internal/streams/duplexpair", UnionBytes(&internal_streams_duplexpair_resource) },
    {"internal/streams/end-of-stream", UnionBytes(&internal_streams_end_of_stream_resource) },
    {"internal/streams/from", UnionBytes(&internal_streams_from_resource) },
    {"internal/streams/lazy_transform", UnionBytes(&internal_streams_lazy_transform_resource) },
    {"internal/streams/legacy", UnionBytes(&internal_streams_legacy_resource) },
    {"internal/streams/operators", UnionBytes(&internal_streams_operators_resource) },
    {"internal/streams/passthrough", UnionBytes(&internal_streams_passthrough_resource) },
    {"internal/streams/pipeline", UnionBytes(&internal_streams_pipeline_resource) },
    {"internal/streams/readable", UnionBytes(&internal_streams_readable_resource) },
    {"internal/streams/state", UnionBytes(&internal_streams_state_resource) },
    {"internal/streams/transform", UnionBytes(&internal_streams_transform_resource) },
    {"internal/streams/utils", UnionBytes(&internal_streams_utils_resource) },
    {"internal/streams/writable", UnionBytes(&internal_streams_writable_resource) },
    {"internal/test/binding", UnionBytes(&internal_test_binding_resource) },
    {"internal/test/transfer", UnionBytes(&internal_test_transfer_resource) },
    {"internal/test_runner/assert", UnionBytes(&internal_test_runner_assert_resource) },
    {"internal/test_runner/coverage", UnionBytes(&internal_test_runner_coverage_resource) },
    {"internal/test_runner/harness", UnionBytes(&internal_test_runner_harness_resource) },
    {"internal/test_runner/mock/loader", UnionBytes(&internal_test_runner_mock_loader_resource) },
    {"internal/test_runner/mock/mock", UnionBytes(&internal_test_runner_mock_mock_resource) },
    {"internal/test_runner/mock/mock_timers", UnionBytes(&internal_test_runner_mock_mock_timers_resource) },
    {"internal/test_runner/reporter/dot", UnionBytes(&internal_test_runner_reporter_dot_resource) },
    {"internal/test_runner/reporter/junit", UnionBytes(&internal_test_runner_reporter_junit_resource) },
    {"internal/test_runner/reporter/lcov", UnionBytes(&internal_test_runner_reporter_lcov_resource) },
    {"internal/test_runner/reporter/spec", UnionBytes(&internal_test_runner_reporter_spec_resource) },
    {"internal/test_runner/reporter/tap", UnionBytes(&internal_test_runner_reporter_tap_resource) },
    {"internal/test_runner/reporter/utils", UnionBytes(&internal_test_runner_reporter_utils_resource) },
    {"internal/test_runner/reporter/v8-serializer", UnionBytes(&internal_test_runner_reporter_v8_serializer_resource) },
    {"internal/test_runner/runner", UnionBytes(&internal_test_runner_runner_resource) },
    {"internal/test_runner/snapshot", UnionBytes(&internal_test_runner_snapshot_resource) },
    {"internal/test_runner/test", UnionBytes(&internal_test_runner_test_resource) },
    {"internal/test_runner/tests_stream", UnionBytes(&internal_test_runner_tests_stream_resource) },
    {"internal/test_runner/utils", UnionBytes(&internal_test_runner_utils_resource) },
    {"internal/timers", UnionBytes(&internal_timers_resource) },
    {"internal/tls/secure-context", UnionBytes(&internal_tls_secure_context_resource) },
    {"internal/trace_events_async_hooks", UnionBytes(&internal_trace_events_async_hooks_resource) },
    {"internal/tty", UnionBytes(&internal_tty_resource) },
    {"internal/url", UnionBytes(&internal_url_resource) },
    {"internal/util", UnionBytes(&internal_util_resource) },
    {"internal/util/colors", UnionBytes(&internal_util_colors_resource) },
    {"internal/util/comparisons", UnionBytes(&internal_util_comparisons_resource) },
    {"internal/util/debuglog", UnionBytes(&internal_util_debuglog_resource) },
    {"internal/util/diff", UnionBytes(&internal_util_diff_resource) },
    {"internal/util/inspect", UnionBytes(&internal_util_inspect_resource) },
    {"internal/util/inspector", UnionBytes(&internal_util_inspector_resource) },
    {"internal/util/parse_args/parse_args", UnionBytes(&internal_util_parse_args_parse_args_resource) },
    {"internal/util/parse_args/utils", UnionBytes(&internal_util_parse_args_utils_resource) },
    {"internal/util/types", UnionBytes(&internal_util_types_resource) },
    {"internal/v8/startup_snapshot", UnionBytes(&internal_v8_startup_snapshot_resource) },
    {"internal/v8_prof_polyfill", UnionBytes(&internal_v8_prof_polyfill_resource) },
    {"internal/v8_prof_processor", UnionBytes(&internal_v8_prof_processor_resource) },
    {"internal/validators", UnionBytes(&internal_validators_resource) },
    {"internal/vm", UnionBytes(&internal_vm_resource) },
    {"internal/vm/module", UnionBytes(&internal_vm_module_resource) },
    {"internal/wasm_web_api", UnionBytes(&internal_wasm_web_api_resource) },
    {"internal/watch_mode/files_watcher", UnionBytes(&internal_watch_mode_files_watcher_resource) },
    {"internal/watchdog", UnionBytes(&internal_watchdog_resource) },
    {"internal/webidl", UnionBytes(&internal_webidl_resource) },
    {"internal/webstorage", UnionBytes(&internal_webstorage_resource) },
    {"internal/webstreams/adapters", UnionBytes(&internal_webstreams_adapters_resource) },
    {"internal/webstreams/compression", UnionBytes(&internal_webstreams_compression_resource) },
    {"internal/webstreams/encoding", UnionBytes(&internal_webstreams_encoding_resource) },
    {"internal/webstreams/queuingstrategies", UnionBytes(&internal_webstreams_queuingstrategies_resource) },
    {"internal/webstreams/readablestream", UnionBytes(&internal_webstreams_readablestream_resource) },
    {"internal/webstreams/transfer", UnionBytes(&internal_webstreams_transfer_resource) },
    {"internal/webstreams/transformstream", UnionBytes(&internal_webstreams_transformstream_resource) },
    {"internal/webstreams/util", UnionBytes(&internal_webstreams_util_resource) },
    {"internal/webstreams/writablestream", UnionBytes(&internal_webstreams_writablestream_resource) },
    {"internal/worker", UnionBytes(&internal_worker_resource) },
    {"internal/worker/io", UnionBytes(&internal_worker_io_resource) },
    {"internal/worker/js_transferable", UnionBytes(&internal_worker_js_transferable_resource) },
    {"internal/worker/messaging", UnionBytes(&internal_worker_messaging_resource) },
    {"module", UnionBytes(&module_resource) },
    {"net", UnionBytes(&net_resource) },
    {"os", UnionBytes(&os_resource) },
    {"path", UnionBytes(&path_resource) },
    {"path/posix", UnionBytes(&path_posix_resource) },
    {"path/win32", UnionBytes(&path_win32_resource) },
    {"perf_hooks", UnionBytes(&perf_hooks_resource) },
    {"process", UnionBytes(&process_resource) },
    {"punycode", UnionBytes(&punycode_resource) },
    {"querystring", UnionBytes(&querystring_resource) },
    {"quic", UnionBytes(&quic_resource) },
    {"readline", UnionBytes(&readline_resource) },
    {"readline/promises", UnionBytes(&readline_promises_resource) },
    {"repl", UnionBytes(&repl_resource) },
    {"sea", UnionBytes(&sea_resource) },
    {"sqlite", UnionBytes(&sqlite_resource) },
    {"stream", UnionBytes(&stream_resource) },
    {"stream/consumers", UnionBytes(&stream_consumers_resource) },
    {"stream/promises", UnionBytes(&stream_promises_resource) },
    {"stream/web", UnionBytes(&stream_web_resource) },
    {"string_decoder", UnionBytes(&string_decoder_resource) },
    {"sys", UnionBytes(&sys_resource) },
    {"test", UnionBytes(&test_resource) },
    {"test/reporters", UnionBytes(&test_reporters_resource) },
    {"timers", UnionBytes(&timers_resource) },
    {"timers/promises", UnionBytes(&timers_promises_resource) },
    {"tls", UnionBytes(&tls_resource) },
    {"trace_events", UnionBytes(&trace_events_resource) },
    {"tty", UnionBytes(&tty_resource) },
    {"url", UnionBytes(&url_resource) },
    {"util", UnionBytes(&util_resource) },
    {"util/types", UnionBytes(&util_types_resource) },
    {"v8", UnionBytes(&v8_resource) },
    {"vm", UnionBytes(&vm_resource) },
    {"wasi", UnionBytes(&wasi_resource) },
    {"worker_threads", UnionBytes(&worker_threads_resource) },
    {"zlib", UnionBytes(&zlib_resource) },
    {"internal/deps/v8/tools/arguments", UnionBytes(&internal_deps_v8_tools_arguments_resource) },
    {"internal/deps/v8/tools/codemap", UnionBytes(&internal_deps_v8_tools_codemap_resource) },
    {"internal/deps/v8/tools/consarray", UnionBytes(&internal_deps_v8_tools_consarray_resource) },
    {"internal/deps/v8/tools/csvparser", UnionBytes(&internal_deps_v8_tools_csvparser_resource) },
    {"internal/deps/v8/tools/logreader", UnionBytes(&internal_deps_v8_tools_logreader_resource) },
    {"internal/deps/v8/tools/profile", UnionBytes(&internal_deps_v8_tools_profile_resource) },
    {"internal/deps/v8/tools/profile_view", UnionBytes(&internal_deps_v8_tools_profile_view_resource) },
    {"internal/deps/v8/tools/sourcemap", UnionBytes(&internal_deps_v8_tools_sourcemap_resource) },
    {"internal/deps/v8/tools/splaytree", UnionBytes(&internal_deps_v8_tools_splaytree_resource) },
    {"internal/deps/v8/tools/tickprocessor-driver", UnionBytes(&internal_deps_v8_tools_tickprocessor_driver_resource) },
    {"internal/deps/v8/tools/tickprocessor", UnionBytes(&internal_deps_v8_tools_tickprocessor_resource) },
  }  // BuiltinSourceMap
};  // ThreadsafeCopyOnWrite
}  // anonymous namespace

void BuiltinLoader::LoadJavaScriptSource() {
  source_ = global_source_map;
}

void RegisterExternalReferencesForInternalizedBuiltinCode(
  ExternalReferenceRegistry* registry) {
  registry->Register(&internal_deps_acorn_acorn_walk_dist_walk_resource);
  registry->Register(&internal_deps_acorn_acorn_dist_acorn_resource);
  registry->Register(&internal_deps_amaro_dist_index_resource);
  registry->Register(&internal_deps_cjs_module_lexer_dist_lexer_resource);
  registry->Register(&internal_deps_cjs_module_lexer_lexer_resource);
  registry->Register(&internal_deps_minimatch_index_resource);
  registry->Register(&internal_deps_undici_undici_resource);
  registry->Register(&_http_agent_resource);
  registry->Register(&_http_client_resource);
  registry->Register(&_http_common_resource);
  registry->Register(&_http_incoming_resource);
  registry->Register(&_http_outgoing_resource);
  registry->Register(&_http_server_resource);
  registry->Register(&_stream_duplex_resource);
  registry->Register(&_stream_passthrough_resource);
  registry->Register(&_stream_readable_resource);
  registry->Register(&_stream_transform_resource);
  registry->Register(&_stream_wrap_resource);
  registry->Register(&_stream_writable_resource);
  registry->Register(&_tls_common_resource);
  registry->Register(&_tls_wrap_resource);
  registry->Register(&assert_resource);
  registry->Register(&assert_strict_resource);
  registry->Register(&async_hooks_resource);
  registry->Register(&buffer_resource);
  registry->Register(&child_process_resource);
  registry->Register(&cluster_resource);
  registry->Register(&console_resource);
  registry->Register(&constants_resource);
  registry->Register(&crypto_resource);
  registry->Register(&dgram_resource);
  registry->Register(&diagnostics_channel_resource);
  registry->Register(&dns_resource);
  registry->Register(&dns_promises_resource);
  registry->Register(&domain_resource);
  registry->Register(&events_resource);
  registry->Register(&fs_resource);
  registry->Register(&fs_promises_resource);
  registry->Register(&http_resource);
  registry->Register(&http2_resource);
  registry->Register(&https_resource);
  registry->Register(&inspector_resource);
  registry->Register(&inspector_promises_resource);
  registry->Register(&internal_abort_controller_resource);
  registry->Register(&internal_assert_resource);
  registry->Register(&internal_assert_assertion_error_resource);
  registry->Register(&internal_assert_calltracker_resource);
  registry->Register(&internal_assert_myers_diff_resource);
  registry->Register(&internal_assert_utils_resource);
  registry->Register(&internal_async_context_frame_resource);
  registry->Register(&internal_async_hooks_resource);
  registry->Register(&internal_async_local_storage_async_context_frame_resource);
  registry->Register(&internal_async_local_storage_async_hooks_resource);
  registry->Register(&internal_blob_resource);
  registry->Register(&internal_blocklist_resource);
  registry->Register(&internal_bootstrap_node_resource);
  registry->Register(&internal_bootstrap_realm_resource);
  registry->Register(&internal_bootstrap_shadow_realm_resource);
  registry->Register(&internal_bootstrap_switches_does_not_own_process_state_resource);
  registry->Register(&internal_bootstrap_switches_does_own_process_state_resource);
  registry->Register(&internal_bootstrap_switches_is_main_thread_resource);
  registry->Register(&internal_bootstrap_switches_is_not_main_thread_resource);
  registry->Register(&internal_bootstrap_web_exposed_wildcard_resource);
  registry->Register(&internal_bootstrap_web_exposed_window_or_worker_resource);
  registry->Register(&internal_buffer_resource);
  registry->Register(&internal_child_process_resource);
  registry->Register(&internal_child_process_serialization_resource);
  registry->Register(&internal_cli_table_resource);
  registry->Register(&internal_cluster_child_resource);
  registry->Register(&internal_cluster_primary_resource);
  registry->Register(&internal_cluster_round_robin_handle_resource);
  registry->Register(&internal_cluster_shared_handle_resource);
  registry->Register(&internal_cluster_utils_resource);
  registry->Register(&internal_cluster_worker_resource);
  registry->Register(&internal_console_constructor_resource);
  registry->Register(&internal_console_global_resource);
  registry->Register(&internal_constants_resource);
  registry->Register(&internal_crypto_aes_resource);
  registry->Register(&internal_crypto_certificate_resource);
  registry->Register(&internal_crypto_cfrg_resource);
  registry->Register(&internal_crypto_cipher_resource);
  registry->Register(&internal_crypto_diffiehellman_resource);
  registry->Register(&internal_crypto_ec_resource);
  registry->Register(&internal_crypto_hash_resource);
  registry->Register(&internal_crypto_hashnames_resource);
  registry->Register(&internal_crypto_hkdf_resource);
  registry->Register(&internal_crypto_keygen_resource);
  registry->Register(&internal_crypto_keys_resource);
  registry->Register(&internal_crypto_mac_resource);
  registry->Register(&internal_crypto_pbkdf2_resource);
  registry->Register(&internal_crypto_random_resource);
  registry->Register(&internal_crypto_rsa_resource);
  registry->Register(&internal_crypto_scrypt_resource);
  registry->Register(&internal_crypto_sig_resource);
  registry->Register(&internal_crypto_util_resource);
  registry->Register(&internal_crypto_webcrypto_resource);
  registry->Register(&internal_crypto_webidl_resource);
  registry->Register(&internal_crypto_x509_resource);
  registry->Register(&internal_data_url_resource);
  registry->Register(&internal_debugger_inspect_resource);
  registry->Register(&internal_debugger_inspect_client_resource);
  registry->Register(&internal_debugger_inspect_repl_resource);
  registry->Register(&internal_dgram_resource);
  registry->Register(&internal_dns_callback_resolver_resource);
  registry->Register(&internal_dns_promises_resource);
  registry->Register(&internal_dns_utils_resource);
  registry->Register(&internal_encoding_resource);
  registry->Register(&internal_error_serdes_resource);
  registry->Register(&internal_errors_resource);
  registry->Register(&internal_event_target_resource);
  registry->Register(&internal_events_abort_listener_resource);
  registry->Register(&internal_events_symbols_resource);
  registry->Register(&internal_file_resource);
  registry->Register(&internal_fixed_queue_resource);
  registry->Register(&internal_freelist_resource);
  registry->Register(&internal_freeze_intrinsics_resource);
  registry->Register(&internal_fs_cp_cp_sync_resource);
  registry->Register(&internal_fs_cp_cp_resource);
  registry->Register(&internal_fs_dir_resource);
  registry->Register(&internal_fs_glob_resource);
  registry->Register(&internal_fs_promises_resource);
  registry->Register(&internal_fs_read_context_resource);
  registry->Register(&internal_fs_recursive_watch_resource);
  registry->Register(&internal_fs_rimraf_resource);
  registry->Register(&internal_fs_streams_resource);
  registry->Register(&internal_fs_sync_write_stream_resource);
  registry->Register(&internal_fs_utils_resource);
  registry->Register(&internal_fs_watchers_resource);
  registry->Register(&internal_heap_utils_resource);
  registry->Register(&internal_histogram_resource);
  registry->Register(&internal_http_resource);
  registry->Register(&internal_http2_compat_resource);
  registry->Register(&internal_http2_core_resource);
  registry->Register(&internal_http2_util_resource);
  registry->Register(&internal_inspector_network_resource);
  registry->Register(&internal_inspector_network_http_resource);
  registry->Register(&internal_inspector_network_undici_resource);
  registry->Register(&internal_inspector_async_hook_resource);
  registry->Register(&internal_inspector_network_tracking_resource);
  registry->Register(&internal_js_stream_socket_resource);
  registry->Register(&internal_legacy_processbinding_resource);
  registry->Register(&internal_linkedlist_resource);
  registry->Register(&internal_main_check_syntax_resource);
  registry->Register(&internal_main_embedding_resource);
  registry->Register(&internal_main_eval_stdin_resource);
  registry->Register(&internal_main_eval_string_resource);
  registry->Register(&internal_main_inspect_resource);
  registry->Register(&internal_main_mksnapshot_resource);
  registry->Register(&internal_main_print_help_resource);
  registry->Register(&internal_main_prof_process_resource);
  registry->Register(&internal_main_repl_resource);
  registry->Register(&internal_main_run_main_module_resource);
  registry->Register(&internal_main_test_runner_resource);
  registry->Register(&internal_main_watch_mode_resource);
  registry->Register(&internal_main_worker_thread_resource);
  registry->Register(&internal_mime_resource);
  registry->Register(&internal_modules_cjs_loader_resource);
  registry->Register(&internal_modules_customization_hooks_resource);
  registry->Register(&internal_modules_esm_assert_resource);
  registry->Register(&internal_modules_esm_create_dynamic_module_resource);
  registry->Register(&internal_modules_esm_formats_resource);
  registry->Register(&internal_modules_esm_get_format_resource);
  registry->Register(&internal_modules_esm_hooks_resource);
  registry->Register(&internal_modules_esm_initialize_import_meta_resource);
  registry->Register(&internal_modules_esm_load_resource);
  registry->Register(&internal_modules_esm_loader_resource);
  registry->Register(&internal_modules_esm_module_job_resource);
  registry->Register(&internal_modules_esm_module_map_resource);
  registry->Register(&internal_modules_esm_resolve_resource);
  registry->Register(&internal_modules_esm_shared_constants_resource);
  registry->Register(&internal_modules_esm_translators_resource);
  registry->Register(&internal_modules_esm_utils_resource);
  registry->Register(&internal_modules_esm_worker_resource);
  registry->Register(&internal_modules_helpers_resource);
  registry->Register(&internal_modules_package_json_reader_resource);
  registry->Register(&internal_modules_run_main_resource);
  registry->Register(&internal_modules_typescript_resource);
  registry->Register(&internal_navigator_resource);
  registry->Register(&internal_net_resource);
  registry->Register(&internal_options_resource);
  registry->Register(&internal_per_context_domexception_resource);
  registry->Register(&internal_per_context_messageport_resource);
  registry->Register(&internal_per_context_primordials_resource);
  registry->Register(&internal_perf_event_loop_delay_resource);
  registry->Register(&internal_perf_event_loop_utilization_resource);
  registry->Register(&internal_perf_nodetiming_resource);
  registry->Register(&internal_perf_observe_resource);
  registry->Register(&internal_perf_performance_resource);
  registry->Register(&internal_perf_performance_entry_resource);
  registry->Register(&internal_perf_resource_timing_resource);
  registry->Register(&internal_perf_timerify_resource);
  registry->Register(&internal_perf_usertiming_resource);
  registry->Register(&internal_perf_utils_resource);
  registry->Register(&internal_priority_queue_resource);
  registry->Register(&internal_process_execution_resource);
  registry->Register(&internal_process_finalization_resource);
  registry->Register(&internal_process_per_thread_resource);
  registry->Register(&internal_process_permission_resource);
  registry->Register(&internal_process_pre_execution_resource);
  registry->Register(&internal_process_promises_resource);
  registry->Register(&internal_process_report_resource);
  registry->Register(&internal_process_signal_resource);
  registry->Register(&internal_process_task_queues_resource);
  registry->Register(&internal_process_warning_resource);
  registry->Register(&internal_process_worker_thread_only_resource);
  registry->Register(&internal_promise_hooks_resource);
  registry->Register(&internal_querystring_resource);
  registry->Register(&internal_quic_quic_resource);
  registry->Register(&internal_quic_state_resource);
  registry->Register(&internal_quic_stats_resource);
  registry->Register(&internal_quic_symbols_resource);
  registry->Register(&internal_readline_callbacks_resource);
  registry->Register(&internal_readline_emitKeypressEvents_resource);
  registry->Register(&internal_readline_interface_resource);
  registry->Register(&internal_readline_promises_resource);
  registry->Register(&internal_readline_utils_resource);
  registry->Register(&internal_repl_resource);
  registry->Register(&internal_repl_await_resource);
  registry->Register(&internal_repl_history_resource);
  registry->Register(&internal_repl_utils_resource);
  registry->Register(&internal_socket_list_resource);
  registry->Register(&internal_socketaddress_resource);
  registry->Register(&internal_source_map_prepare_stack_trace_resource);
  registry->Register(&internal_source_map_source_map_resource);
  registry->Register(&internal_source_map_source_map_cache_resource);
  registry->Register(&internal_source_map_source_map_cache_map_resource);
  registry->Register(&internal_stream_base_commons_resource);
  registry->Register(&internal_streams_add_abort_signal_resource);
  registry->Register(&internal_streams_compose_resource);
  registry->Register(&internal_streams_destroy_resource);
  registry->Register(&internal_streams_duplex_resource);
  registry->Register(&internal_streams_duplexify_resource);
  registry->Register(&internal_streams_duplexpair_resource);
  registry->Register(&internal_streams_end_of_stream_resource);
  registry->Register(&internal_streams_from_resource);
  registry->Register(&internal_streams_lazy_transform_resource);
  registry->Register(&internal_streams_legacy_resource);
  registry->Register(&internal_streams_operators_resource);
  registry->Register(&internal_streams_passthrough_resource);
  registry->Register(&internal_streams_pipeline_resource);
  registry->Register(&internal_streams_readable_resource);
  registry->Register(&internal_streams_state_resource);
  registry->Register(&internal_streams_transform_resource);
  registry->Register(&internal_streams_utils_resource);
  registry->Register(&internal_streams_writable_resource);
  registry->Register(&internal_test_binding_resource);
  registry->Register(&internal_test_transfer_resource);
  registry->Register(&internal_test_runner_assert_resource);
  registry->Register(&internal_test_runner_coverage_resource);
  registry->Register(&internal_test_runner_harness_resource);
  registry->Register(&internal_test_runner_mock_loader_resource);
  registry->Register(&internal_test_runner_mock_mock_resource);
  registry->Register(&internal_test_runner_mock_mock_timers_resource);
  registry->Register(&internal_test_runner_reporter_dot_resource);
  registry->Register(&internal_test_runner_reporter_junit_resource);
  registry->Register(&internal_test_runner_reporter_lcov_resource);
  registry->Register(&internal_test_runner_reporter_spec_resource);
  registry->Register(&internal_test_runner_reporter_tap_resource);
  registry->Register(&internal_test_runner_reporter_utils_resource);
  registry->Register(&internal_test_runner_reporter_v8_serializer_resource);
  registry->Register(&internal_test_runner_runner_resource);
  registry->Register(&internal_test_runner_snapshot_resource);
  registry->Register(&internal_test_runner_test_resource);
  registry->Register(&internal_test_runner_tests_stream_resource);
  registry->Register(&internal_test_runner_utils_resource);
  registry->Register(&internal_timers_resource);
  registry->Register(&internal_tls_secure_context_resource);
  registry->Register(&internal_trace_events_async_hooks_resource);
  registry->Register(&internal_tty_resource);
  registry->Register(&internal_url_resource);
  registry->Register(&internal_util_resource);
  registry->Register(&internal_util_colors_resource);
  registry->Register(&internal_util_comparisons_resource);
  registry->Register(&internal_util_debuglog_resource);
  registry->Register(&internal_util_diff_resource);
  registry->Register(&internal_util_inspect_resource);
  registry->Register(&internal_util_inspector_resource);
  registry->Register(&internal_util_parse_args_parse_args_resource);
  registry->Register(&internal_util_parse_args_utils_resource);
  registry->Register(&internal_util_types_resource);
  registry->Register(&internal_v8_startup_snapshot_resource);
  registry->Register(&internal_v8_prof_polyfill_resource);
  registry->Register(&internal_v8_prof_processor_resource);
  registry->Register(&internal_validators_resource);
  registry->Register(&internal_vm_resource);
  registry->Register(&internal_vm_module_resource);
  registry->Register(&internal_wasm_web_api_resource);
  registry->Register(&internal_watch_mode_files_watcher_resource);
  registry->Register(&internal_watchdog_resource);
  registry->Register(&internal_webidl_resource);
  registry->Register(&internal_webstorage_resource);
  registry->Register(&internal_webstreams_adapters_resource);
  registry->Register(&internal_webstreams_compression_resource);
  registry->Register(&internal_webstreams_encoding_resource);
  registry->Register(&internal_webstreams_queuingstrategies_resource);
  registry->Register(&internal_webstreams_readablestream_resource);
  registry->Register(&internal_webstreams_transfer_resource);
  registry->Register(&internal_webstreams_transformstream_resource);
  registry->Register(&internal_webstreams_util_resource);
  registry->Register(&internal_webstreams_writablestream_resource);
  registry->Register(&internal_worker_resource);
  registry->Register(&internal_worker_io_resource);
  registry->Register(&internal_worker_js_transferable_resource);
  registry->Register(&internal_worker_messaging_resource);
  registry->Register(&module_resource);
  registry->Register(&net_resource);
  registry->Register(&os_resource);
  registry->Register(&path_resource);
  registry->Register(&path_posix_resource);
  registry->Register(&path_win32_resource);
  registry->Register(&perf_hooks_resource);
  registry->Register(&process_resource);
  registry->Register(&punycode_resource);
  registry->Register(&querystring_resource);
  registry->Register(&quic_resource);
  registry->Register(&readline_resource);
  registry->Register(&readline_promises_resource);
  registry->Register(&repl_resource);
  registry->Register(&sea_resource);
  registry->Register(&sqlite_resource);
  registry->Register(&stream_resource);
  registry->Register(&stream_consumers_resource);
  registry->Register(&stream_promises_resource);
  registry->Register(&stream_web_resource);
  registry->Register(&string_decoder_resource);
  registry->Register(&sys_resource);
  registry->Register(&test_resource);
  registry->Register(&test_reporters_resource);
  registry->Register(&timers_resource);
  registry->Register(&timers_promises_resource);
  registry->Register(&tls_resource);
  registry->Register(&trace_events_resource);
  registry->Register(&tty_resource);
  registry->Register(&url_resource);
  registry->Register(&util_resource);
  registry->Register(&util_types_resource);
  registry->Register(&v8_resource);
  registry->Register(&vm_resource);
  registry->Register(&wasi_resource);
  registry->Register(&worker_threads_resource);
  registry->Register(&zlib_resource);
  registry->Register(&internal_deps_v8_tools_arguments_resource);
  registry->Register(&internal_deps_v8_tools_codemap_resource);
  registry->Register(&internal_deps_v8_tools_consarray_resource);
  registry->Register(&internal_deps_v8_tools_csvparser_resource);
  registry->Register(&internal_deps_v8_tools_logreader_resource);
  registry->Register(&internal_deps_v8_tools_profile_resource);
  registry->Register(&internal_deps_v8_tools_profile_view_resource);
  registry->Register(&internal_deps_v8_tools_sourcemap_resource);
  registry->Register(&internal_deps_v8_tools_splaytree_resource);
  registry->Register(&internal_deps_v8_tools_tickprocessor_driver_resource);
  registry->Register(&internal_deps_v8_tools_tickprocessor_resource);
}

UnionBytes BuiltinLoader::GetConfig() {
  return UnionBytes(&config_resource);
}

}  // namespace builtins

}  // namespace node

