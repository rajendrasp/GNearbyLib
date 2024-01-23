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

# target internal_platform_implementation_linux_types
add_library(internal_platform_implementation_linux_types
    "atomic_boolean.h"
    "atomic_reference.h"
    "atomic_uint32.h"
    "bluetooth_adapter.h"
    "condition_variable.h"
    "device_info.h"
    "executor.h"
    "future.h"
    "mutex.h"
    "preferences_manager.h"
    "preferences_repository.h"
    "scheduled_executor.h"
    "submittable_executor.h"
    "timer.h"
    "thread_pool.h"
    "log_message.h"
    "utils.h"
    "device_info.cc"
    "log_message.cc"
    "timer.cc"
)

target_link_libraries(internal_platform_implementation_linux_types
  PUBLIC
    internal::platform::implementation::linux::comm
    internal::platform::implementation::types
    absl::strings
    PkgConfig::libsystemd
    SDBusCpp::sdbus-c++
    rt
)

target_include_directories(internal_platform_implementation_linux_types PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::implementation::linux::types ALIAS internal_platform_implementation_linux_types)

# target internal_platform_implementation_linux_comm
add_library(internal_platform_implementation_linux_comm
  INTERFACE
    "avahi.h"
    "ble_medium.h"
    "ble_v2_medium.h"
    "bluetooth_adapter.h"
    "bluetooth_bluez_profile.h"
    "bluetooth_classic_device.h"
    "bluetooth_classic_medium.h"
    "bluetooth_classic_server_socket.h"
    "bluetooth_classic_socket.h"
    "bluetooth_devices.h"
    "bluetooth_pairing.h"
    "bluez.h"
    "dbus.h"
    "network_manager.h"
    "network_manager_active_connection.h"
    "network_manager_access_point.h"
    "stream.h"
    "wifi_direct.h"
    "wifi_direct_server_socket.h"
    "wifi_direct_socket.h"
    "wifi_hotspot.h"
    "wifi_hotspot_server_socket.h"
    "wifi_hotspot_socket.h"
    "wifi_lan.h"
    "wifi_lan_server_socket.h"
    "wifi_lan_socket.h"
    "wifi_medium.h"
    "wifi_socket.h"
)

target_link_libraries(internal_platform_implementation_linux_comm
  INTERFACE
    internal::platform::base
    internal::platform::comm
    internal::platform::types
    internal::platform::uuid
    internal::platform::implementation::comm
    internal::platform::implementation::types
    internal::platform::implementation::linux::generated::types
    absl::core_headers
    absl::flat_hash_map
    absl::flat_hash_set
    absl::any_invocable
    absl::memory
    absl::status
    absl::statusor
    absl::strings
    absl::synchronization
    absl::time
    absl::optional
    PkgConfig::libsystemd
    SDBusCpp::sdbus-c++
)

target_include_directories(internal_platform_implementation_linux_comm INTERFACE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::implementation::linux::comm ALIAS internal_platform_implementation_linux_comm)

# target internal_platform_implementation_linux_crypto
add_library(internal_platform_implementation_linux_crypto
    "crypto.cc"
)

target_link_libraries(internal_platform_implementation_linux_crypto
  PUBLIC
    internal::platform::base
    internal::platform::implementation::types
    boringssl::crypto
    absl::strings
)

target_include_directories(internal_platform_implementation_linux_crypto PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::implementation::linux::crypto ALIAS internal_platform_implementation_linux_crypto)

# target internal_platform_implementation_linux
add_library(internal_platform_implementation_linux
    "avahi.cc"
    "bluetooth_adapter.cc"
    "bluetooth_bluez_profile.cc"
    "bluetooth_classic_device.cc"
    "bluetooth_classic_medium.cc"
    "bluetooth_classic_socket.cc"
    "bluetooth_classic_server_socket.cc"
    "bluetooth_devices.cc"
    "bluetooth_pairing.cc"
    "bluez.cc"
    "dbus.cc"
    "executor.cc"
    "network_manager.cc"
    "network_manager_active_connection.cc"
    "platform.cc"
    "preferences_manager.cc"
    "preferences_repository.cc"
    "scheduled_executor.cc"
    "stream.cc"
    "submittable_executor.cc"
    "system_clock.cc"
    "thread_pool.cc"
    "utils.cc"
    "wifi_direct.cc"
    "wifi_direct_server_socket.cc"
    "wifi_hotspot.cc"
    "wifi_hotspot_server_socket.cc"
    "wifi_lan.cc"
    "wifi_lan_server_socket.cc"
    "wifi_medium.cc"
)

target_link_libraries(internal_platform_implementation_linux
  PUBLIC
    internal::platform::implementation::comm
    internal::platform::implementation::linux::crypto
    internal::platform::implementation::linux::types
    internal::flags::nearby_flags
    internal::platform::base
    internal::platform::cancellation_flag
    internal::platform::comm
    internal::platform::types
    internal::platform::uuid
    internal::platform::flags::platform_flags
    internal::platform::implementation::comm
    internal::platform::implementation::platform
    internal::platform::implementation::types
    internal::platform::implementation::shared::count_down_latch
    internal::platform::implementation::shared::file
    internal::platform::implementation::linux::generated::types
    absl::core_headers
    absl::flat_hash_map
    absl::status
    absl::statusor
    absl::strings
    absl::str_format
    absl::synchronization
    absl::time
    absl::optional
    nlohmann_json::nlohmann_json
    PkgConfig::libsystemd
    SDBusCpp::sdbus-c++
    PkgConfig::libcurl
)

target_include_directories(internal_platform_implementation_linux PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::imlementation::linux ALIAS internal_platform_implementation_linux)

# target internal_platform_implementation_linux_test_utils
add_library(internal_platform_implementation_linux_test_utils
  STATIC
    "test_utils.cc"
    "test_data.h"
    "test_utils.h"
)

target_link_libraries(internal_platform_implementation_linux_test_utils
  PUBLIC
    internal::platform::base
    SDBusCpp::sdbus-c++
    nlohmann_json::nlohmann_json
)

target_include_directories(internal_platform_implementation_linux_test_utils PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::implementation::linux::test_utils ALIAS internal_platform_implementation_linux_test_utils)

# target internal_platform_implementation_linux_impl_test

add_subdirectory("generated")
