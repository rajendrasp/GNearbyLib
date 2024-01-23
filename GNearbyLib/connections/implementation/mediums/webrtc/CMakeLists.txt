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

# target connections_implementation_mediums_webrtc_webrtc
add_library(connections_implementation_mediums_webrtc_webrtc
    "connection_flow.cc"
    "signaling_frames.cc"
    "connection_flow.h"
    "data_channel_listener.h"
    "local_ice_candidate_listener.h"
    "session_description_wrapper.h"
    "signaling_frames.h"
)

target_link_libraries(connections_implementation_mediums_webrtc_webrtc
  PUBLIC
    connections_implementation_mediums_webrtc_data_types
    connections_core_types
    connections_implementation_mediums_utils
    internal_platform_base
    internal_platform_comm
    internal_platform_logging
    internal_platform_types
    web_rtc_signaling_frames_cc_proto
    # TODO: Support WebRTC
    absl::memory
    absl::time
)

target_compile_definitions(connections_implementation_mediums_webrtc_webrtc PRIVATE "CORE_ADAPTER_DLL")
target_include_directories(connections_implementation_mediums_webrtc_webrtc PRIVATE ${CMAKE_SOURCE_DIR})

# target connections_implementation_mediums_webrtc_data_types
add_library(connections_implementation_mediums_webrtc_data_types
    "webrtc_socket_impl.cc"
    "webrtc_socket_impl.h"
)

target_link_libraries(connections_implementation_mediums_webrtc_data_types
  PUBLIC
    connections_core_types
    internal_platform_base
    internal_platform_types
    # TODO: Support WebRTC
)

target_compile_definitions(connections_implementation_mediums_webrtc_data_types PRIVATE "CORE_ADAPTER_DLL")
target_include_directories(connections_implementation_mediums_webrtc_data_types PRIVATE ${CMAKE_SOURCE_DIR})

# target connections_implementation_mediums_webrtc_webrtc_test
