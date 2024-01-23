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

# target internal_network_types
add_library(internal_network_types
    "http_request.cc"
    "http_response.cc"
    "http_status_code.cc"
    "url.cc"
    "utils.cc"
    "http_body.h"
    "http_client.h"
    "http_client_factory.h"
    "http_request.h"
    "http_response.h"
    "http_status_code.h"
    "url.h"
    "utils.h"
)

target_link_libraries(internal_network_types
  PUBLIC
    internal::platform::types
    absl::flat_hash_map
    absl::status
    absl::statusor
    absl::strings
)

target_include_directories(internal_network_types PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::network::types ALIAS internal_network_types)

# target internal_network_nearby_http_client
add_library(internal_network_nearby_http_client
    "http_client_impl.cc"
    "debug.h"
    "http_client_factory_impl.h"
    "http_client_impl.h"
)

target_link_libraries(internal_network_nearby_http_client
  PUBLIC
    internal::network::types
    internal::flags::nearby_flags
    internal::platform::logging
    internal::platform::types
    internal::platform::flags::platform_flags
    internal::platform::implementation::platform
    absl::core_headers
    absl::flat_hash_map
    absl::status
    absl::statusor
    absl::str_format
    absl::synchronization
)

target_include_directories(internal_network_nearby_http_client PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::network::nearby_http_client ALIAS internal_network_nearby_http_client)

# target internal_network_nearby_http_client_test
