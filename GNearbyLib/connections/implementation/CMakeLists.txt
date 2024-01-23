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

# target connections_implementation_internal
add_library(connections_implementation_internal
    "base_bwu_handler.cc"
    "base_endpoint_channel.cc"
    "base_pcp_handler.cc"
    "ble_advertisement.cc"
    "ble_endpoint_channel.cc"
    "ble_v2_endpoint_channel.cc"
    "bluetooth_bwu_handler.cc"
    "bluetooth_device_name.cc"
    "bluetooth_endpoint_channel.cc"
    "bwu_manager.cc"
    "client_proxy.cc"
    "encryption_runner.cc"
    "endpoint_channel_manager.cc"
    "endpoint_manager.cc"
    "injected_bluetooth_device_store.cc"
    "internal_payload.cc"
    "internal_payload_factory.cc"
    "offline_frames.cc"
    "offline_frames_validator.cc"
    "offline_service_controller.cc"
    "p2p_cluster_pcp_handler.cc"
    "p2p_point_to_point_pcp_handler.cc"
    "p2p_star_pcp_handler.cc"
    "payload_manager.cc"
    "pcp_manager.cc"
    "service_controller_router.cc"
    "webrtc_bwu_handler.cc"
    "webrtc_bwu_handler_stub.cc"
    "webrtc_endpoint_channel.cc"
    "wifi_direct_bwu_handler.cc"
    "wifi_direct_endpoint_channel.cc"
    "wifi_hotspot_bwu_handler.cc"
    "wifi_hotspot_endpoint_channel.cc"
    "wifi_lan_bwu_handler.cc"
    "wifi_lan_endpoint_channel.cc"
    "wifi_lan_service_info.cc"
    "base_bwu_handler.h"
    "base_endpoint_channel.h"
    "base_pcp_handler.h"
    "ble_advertisement.h"
    "ble_endpoint_channel.h"
    "ble_v2_endpoint_channel.h"
    "bluetooth_bwu_handler.h"
    "bluetooth_device_name.h"
    "bluetooth_endpoint_channel.h"
    "bwu_handler.h"
    "bwu_manager.h"
    "client_proxy.h"
    "encryption_runner.h"
    "endpoint_channel.h"
    "endpoint_channel_manager.h"
    "endpoint_manager.h"
    "injected_bluetooth_device_store.h"
    "internal_payload.h"
    "internal_payload_factory.h"
    "offline_frames.h"
    "offline_frames_validator.h"
    "offline_service_controller.h"
    "p2p_cluster_pcp_handler.h"
    "p2p_point_to_point_pcp_handler.h"
    "p2p_star_pcp_handler.h"
    "payload_manager.h"
    "pcp.h"
    "pcp_handler.h"
    "pcp_manager.h"
    "service_controller.h"
    "service_controller_router.h"
    "service_id_constants.h"
    "webrtc_bwu_handler.h"
    "webrtc_bwu_handler_stub.h"
    "webrtc_endpoint_channel.h"
    "wifi_direct_bwu_handler.h"
    "wifi_direct_endpoint_channel.h"
    "wifi_hotspot_bwu_handler.h"
    "wifi_hotspot_endpoint_channel.h"
    "wifi_lan_bwu_handler.h"
    "wifi_lan_endpoint_channel.h"
    "wifi_lan_service_info.h"
)

target_link_libraries(connections_implementation_internal
  PUBLIC
    connections_core_types
    connections_implementation_analytics_analytics
    connections_implementation_flags_connections_flags
    connections_implementation_mediums_mediums
    connections_implementation_mediums_utils
    offline_wire_formats_cc_proto
    connections_v3_v3_types
    internal_analytics_event_logger
    internal_flags_nearby_flags
    internal_interop_device
    internal_platform_base
    internal_platform_cancellation_flag
    internal_platform_comm
    internal_platform_error_code_recorder
    internal_platform_logging
    internal_platform_types
    internal_platform_util
    internal_platform_implementation_comm
    internal_platform_implementation_platform
    internal_platform_implementation_shared_file
    connections_enums_cc_proto
    absl::core_headers
    absl::btree
    absl::flat_hash_map
    absl::flat_hash_set
    absl::bind_front
    absl::memory
    absl::strings
    absl::str_format
    absl::time
    absl::span
    ukey2::ukey2
)

target_include_directories(connections_implementation_internal PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(connections_implementation_internal PRIVATE "CORE_ADAPTER_DLL")
add_dependencies(connections_implementation_internal ukey2)

# target connections_implementation_message_lite
add_library(connections_implementation_message_lite
  INTERFACE
    "message_lite.h"
)

target_link_libraries(connections_implementation_message_lite
  INTERFACE
    protobuf::libprotobuf-lite
)

target_include_directories(connections_implementation_message_lite INTERFACE ${CMAKE_SOURCE_DIR})

# target connections_implementation_internal_test
add_library(connections_implementation_internal_test
  STATIC
    "offline_simulation_user.cc"
    "simulation_user.cc"
    "fake_bwu_handler.h"
    "fake_endpoint_channel.h"
    "mock_service_controller.h"
    "mock_service_controller_router.h"
    "offline_simulation_user.h"
    "simulation_user.h"
)

target_link_libraries(connections_implementation_internal_test
  PUBLIC
    connections_implementation_internal
    connections_core_types
    internal_platform_base
    internal_platform_test_util
    internal_platform_types
    absl::bind_front
    absl::strings
    GTest::GTest
)

# target connections_implementation_core_internal_test

add_subdirectory("analytics")
add_subdirectory("flags")
add_subdirectory("mediums")
add_subdirectory("proto")
