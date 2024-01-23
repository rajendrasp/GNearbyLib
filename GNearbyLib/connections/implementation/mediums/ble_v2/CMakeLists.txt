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

# target connections_implementation_mediums_ble_v2_ble_v2
add_library(connections_implementation_mediums_ble_v2_ble_v2
    "advertisement_read_result.cc"
    "ble_advertisement.cc"
    "ble_advertisement_header.cc"
    "ble_packet.cc"
    "ble_utils.cc"
    "bloom_filter.cc"
    "discovered_peripheral_tracker.cc"
    "advertisement_read_result.h"
    "ble_advertisement.h"
    "ble_advertisement_header.h"
    "ble_packet.h"
    "ble_utils.h"
    "bloom_filter.h"
    "discovered_peripheral_callback.h"
    "discovered_peripheral_tracker.h"
)

target_link_libraries(connections_implementation_mediums_ble_v2_ble_v2
  PUBLIC
    connections_core_types
    connections_implementation_flags_connections_flags
    connections_implementation_mediums_utils
    internal_flags_nearby_flags
    internal_platform_base
    internal_platform_comm
    internal_platform_logging
    internal_platform_types
    internal_platform_util
    internal_platform_uuid
    ble_frames_cc_proto
    smhasher::SMHasherSupport
    absl::flat_hash_map
    absl::flat_hash_set
    absl::int128
    absl::statusor
    absl::strings
    absl::str_format
    absl::time
    absl::optional
)

target_include_directories(connections_implementation_mediums_ble_v2_ble_v2 PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(connections_implementation_mediums_ble_v2_ble_v2 PRIVATE "CORE_ADAPTER_DLL")

# target connections_implementation_mediums_ble_v2_ble_v2_test
