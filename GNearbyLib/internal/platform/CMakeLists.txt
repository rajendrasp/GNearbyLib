# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# target internal_platform_base
add_library(internal_platform_base
    "base64_utils.cc"
    "bluetooth_utils.cc"
    "input_stream.cc"
    "nsd_service_info.cc"
    "prng.cc"
    "base64_utils.h"
    "bluetooth_utils.h"
    "byte_array.h"
    "callable.h"
    "exception.h"
    "feature_flags.h"
    "input_stream.h"
    "listeners.h"
    "nsd_service_info.h"
    "os_name.h"
    "output_stream.h"
    "payload_id.h"
    "prng.h"
    "runnable.h"
    "socket.h"
    "types.h"
    "wifi_credential.h"
)

target_link_libraries(internal_platform_base
  PUBLIC
    connections_enums_cc_proto
    absl::flat_hash_map
    absl::any_invocable
    absl::type_traits
    absl::strings
    absl::str_format
    absl::synchronization
    absl::time
)

target_include_directories(internal_platform_base PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(internal_platform_base PRIVATE "CORE_ADAPTER_DLL")

add_library(internal::platform::base ALIAS internal_platform_base)

# target internal_platform_util
add_library(internal_platform_util
    "base_input_stream.cc"
    "byte_utils.cc"
    "base_input_stream.h"
    "base_mutex_lock.h"
    "byte_utils.h"
)

target_link_libraries(internal_platform_util
  PUBLIC
    internal::platform::base
    internal::platform::implementation::types
    absl::core_headers
    absl::str_format
)

target_include_directories(internal_platform_util PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::util ALIAS internal_platform_util)

# target internal_platform_logging
add_library(internal_platform_logging
  INTERFACE
    "logging.h"
)

target_link_libraries(internal_platform_logging
  INTERFACE
    internal::platform::implementation::platform
    internal::platform::implementation::types
    glog::glog
)

target_include_directories(internal_platform_logging INTERFACE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::logging ALIAS internal_platform_logging)

# target internal_platform_cancellation_flag
add_library(internal_platform_cancellation_flag
    "cancellation_flag.cc"
    "cancellation_flag.h"
    "cancellation_flag_listener.h"
)

target_link_libraries(internal_platform_cancellation_flag
  PUBLIC
    internal::platform::base
    absl::flat_hash_map
    absl::any_invocable
    absl::synchronization
)

target_include_directories(internal_platform_cancellation_flag PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::cancellation_flag ALIAS internal_platform_cancellation_flag)

# target internal_platform_connection_info
add_library(internal_platform_connection_info
    "ble_connection_info.cc"
    "bluetooth_connection_info.cc"
    "connection_info.cc"
    "wifi_lan_connection_info.cc"
    "ble_connection_info.h"
    "bluetooth_connection_info.h"
    "connection_info.h"
    "wifi_lan_connection_info.h"
)

target_link_libraries(internal_platform_connection_info
  PUBLIC
    internal::platform::types
    connections_enums_cc_proto
    absl::status
    absl::statusor
    absl::strings
    absl::str_format
    absl::variant
)

target_include_directories(internal_platform_connection_info PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::connection_info ALIAS internal_platform_connection_info)

# target internal_platform_error_code_recorder
add_library(internal_platform_error_code_recorder
    "error_code_recorder.cc"
    "error_code_params.h"
    "error_code_recorder.h"
)

target_link_libraries(internal_platform_error_code_recorder
  PUBLIC
    internal::platform::logging
    connections_enums_cc_proto
    error_code_enums_cc_proto
    absl::any_invocable
)

target_include_directories(internal_platform_error_code_recorder PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::error_code_recorder ALIAS internal_platform_error_code_recorder)

# target internal_platform_uuid
add_library(internal_platform_uuid
    "uuid.cc"
    "uuid.h"
)

target_link_libraries(internal_platform_uuid
  PUBLIC
    internal::platform::implementation::types
    absl::strings
)

target_include_directories(internal_platform_uuid PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::uuid ALIAS internal_platform_uuid)

# target internal_platform_test_util

# target internal_platform_test_base

# target internal_platform_util_test

# target internal_platform_cancellation_flag_test

# target internal_platform_error_code_recorder_test

# target internal_platform_types
add_library(internal_platform_types
    "clock_impl.cc"
    "device_info_impl.cc"
    "monitored_runnable.cc"
    "pending_job_registry.cc"
    "pipe.cc"
    "task_runner_impl.cc"
    "timer_impl.cc"
    "atomic_boolean.h"
    "atomic_reference.h"
    "borrowable.h"
    "cancelable.h"
    "cancelable_alarm.h"
    "cancellable_task.h"
    "clock.h"
    "clock_impl.h"
    "condition_variable.h"
    "count_down_latch.h"
    "crypto.h"
    "device_info.h"
    "device_info_impl.h"
    "direct_executor.h"
    "file.h"
    "future.h"
    "lockable.h"
    "logging.h"
    "monitored_runnable.h"
    "multi_thread_executor.h"
    "mutex.h"
    "mutex_lock.h"
    "pending_job_registry.h"
    "pipe.h"
    "scheduled_executor.h"
    "settable_future.h"
    "single_thread_executor.h"
    "submittable_executor.h"
    "system_clock.h"
    "task_runner.h"
    "task_runner_impl.h"
    "thread_check_callable.h"
    "thread_check_runnable.h"
    "timer.h"
    "timer_impl.h"
)

target_link_libraries(internal_platform_types
  PUBLIC
    internal::platform::base
    internal::platform::util
    internal::crypto_cros
    internal::platform::implementation::platform
    internal::platform::implementation::types
    absl::core_headers
    absl::flat_hash_map
    absl::any_invocable
    absl::check
    absl::strings
    absl::synchronization
    absl::time
    glog::glog
)

target_include_directories(internal_platform_types PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::types ALIAS internal_platform_types)

# target internal_platform_comm
add_library(internal_platform_comm
    "ble.cc"
    "ble_v2.cc"
    "bluetooth_classic.cc"
    "credential_storage_impl.cc"
    "file.cc"
    "wifi_direct.cc"
    "wifi_hotspot.cc"
    "wifi_lan.cc"
    "wifi_utils.cc"
    "ble.h"
    "ble_v2.h"
    "bluetooth_adapter.h"
    "bluetooth_classic.h"
    "credential_storage_impl.h"
    "webrtc.h"
    "wifi.h"
    "wifi_direct.h"
    "wifi_hotspot.h"
    "wifi_lan.h"
    "wifi_utils.h"
)

target_link_libraries(internal_platform_comm
  PUBLIC
    internal::platform::base
    internal::platform::cancellation_flag
    internal::platform::types
    internal::platform::uuid
    internal::base
    internal::platform::implementation::comm
    internal::platform::implementation::platform
    # TODO: Support WebRTC
    absl::flat_hash_map
    absl::flat_hash_set
    absl::any_invocable
    absl::status
    absl::strings
    absl::optional
)

add_library(internal::platform::comm ALIAS internal_platform_comm)

# target internal_platform_public_test

add_subdirectory("implementation")
add_subdirectory("flags")
