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

# target connections_implementation_mediums_mediums
add_library(connections_implementation_mediums_mediums
    "ble.cc"
    "ble_v2.cc"
    "bluetooth_classic.cc"
    "bluetooth_radio.cc"
    "mediums.cc"
    "webrtc.cc"
    "webrtc_stub.cc"
    "wifi_direct.cc"
    "wifi_hotspot.cc"
    "wifi_lan.cc"
    "ble.h"
    "ble_v2.h"
    "bluetooth_classic.h"
    "bluetooth_radio.h"
    "mediums.h"
    "webrtc.h"
    "webrtc_stub.h"
    "wifi.h"
    "wifi_direct.h"
    "wifi_hotspot.h"
    "wifi_lan.h"
)

target_link_libraries(connections_implementation_mediums_mediums
  PUBLIC
    connections_implementation_mediums_utils
    connections_core_types
    connections_implementation_flags_connections_flags
    connections_implementation_mediums_ble_v2_ble_v2
    connections_implementation_mediums_webrtc_webrtc
    offline_wire_formats_cc_proto
    internal_flags_nearby_flags
    internal_platform_base
    internal_platform_cancellation_flag
    internal_platform_comm
    internal_platform_logging
    internal_platform_types
    internal_platform_uuid
    web_rtc_signaling_frames_cc_proto
    # TODO: Support WebRTC
    absl::btree
    absl::flat_hash_map
    absl::flat_hash_set
    absl::bind_front
    absl::strings
    absl::str_format
    absl::time
    absl::optional
)

target_include_directories(connections_implementation_mediums_mediums PRIVATE ${CMAKE_SOURCE_DIR})

# target connections_implementation_mediums_utils
add_library(connections_implementation_mediums_utils
    "utils.cc"
    "webrtc_peer_id.cc"
    "webrtc_peer_id_stub.cc"
    "lost_entity_tracker.h"
    "utils.h"
    "webrtc_peer_id.h"
    "webrtc_peer_id_stub.h"
    "webrtc_socket.h"
    "webrtc_socket_stub.h"
)

target_link_libraries(connections_implementation_mediums_utils
  PUBLIC
    connections_implementation_mediums_webrtc_data_types
    offline_wire_formats_cc_proto
    internal_platform_base
    internal_platform_types
    absl::flat_hash_set
    absl::strings
)

target_include_directories(connections_implementation_mediums_utils PRIVATE ${CMAKE_SOURCE_DIR})

# target connections_implementation_mediums_test

# target connections_implementation_mediums_core_internal_mediums_webrtc_test

add_subdirectory("ble_v2")
add_subdirectory("webrtc")
