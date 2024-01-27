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

# target connections_v3_v3_types
add_library(connections_v3_v3_types
    "connections_device.cc"
    "advertising_options.h"
    "bandwidth_info.h"
    "connection_listening_options.h"
    "connection_result.h"
    "connections_device.h"
    "connections_device_provider.h"
    "discovery_options.h"
    "listeners.h"
    "listening_result.h"
    "params.h"
)

target_link_libraries(connections_v3_v3_types
  PUBLIC
    connections_core_types
    internal_crypto
    internal_interop_device
    internal_platform_connection_info
    connections_enums_cc_proto
    absl::any_invocable
)

target_include_directories(connections_v3_v3_types PUBLIC ${CMAKE_SOURCE_DIR})

# target connections_v3_v3_types_test
