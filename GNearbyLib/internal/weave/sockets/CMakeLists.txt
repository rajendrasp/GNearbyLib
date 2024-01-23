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

# target internal_weave_sockets
add_library(internal_weave_sockets
    "client_socket.cc"
    "server_socket.cc"
    "client_socket.h"
    "initial_data_provider.h"
    "server_socket.h"
)

target_link_libraries(internal_weave_sockets
  PUBLIC
    internal::platform::types
    internal::weave
    absl::random_random
    absl::status
)

target_include_directories(internal_weave_sockets PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::weave::sockets ALIAS internal_weave_sockets)

# target internal_weave_sockets_test
