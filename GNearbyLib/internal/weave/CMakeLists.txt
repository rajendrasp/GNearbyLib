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

# target internal_weave
add_library(internal_weave
    "base_socket.cc"
    "message_write_request.cc"
    "packet.cc"
    "packet_sequence_number_generator.cc"
    "packetizer.cc"
    "base_socket.h"
    "connection.h"
    "control_packet_write_request.h"
    "message_write_request.h"
    "packet.h"
    "packet_sequence_number_generator.h"
    "packetizer.h"
    "socket_callback.h"
)

target_link_libraries(internal_weave
  PUBLIC
    internal::platform::base
    internal::platform::types
    absl::core_headers
    absl::any_invocable
    absl::check
    absl::status
    absl::statusor
    absl::strings
    absl::str_format
)

target_include_directories(internal_weave PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::weave ALIAS internal_weave)

# target internal_weave_packet_test

# target internal_weave_packet_sequence_number_generator_tes

# target internal_weave_packetizer_test

# target internal_weave_control_packet_write_request_test

# target internal_weave_message_write_request_test

add_subdirectory("sockets")
