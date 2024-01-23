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

# target internal_base
add_library(internal_base
  INTERFACE
    "observer_list.h"
)

target_link_libraries(internal_base
  INTERFACE
    internal::platform::types
    absl::core_headers
    absl::flat_hash_map
)

target_include_directories(internal_base INTERFACE ${CMAKE_SOURCE_DIR})

add_library(internal::base ALIAS internal_base)

# target internal_base_bluetooth_address
add_library(internal_base_bluetooth_address
    "bluetooth_address.cc"
    "bluetooth_address.h"
)

target_link_libraries(internal_base_bluetooth_address
  PUBLIC
    absl::strings
    absl::str_format
    absl::optional
    absl::span
)

target_include_directories(internal_base_bluetooth_address PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::base::bluetooth_address ALIAS internal_base_bluetooth_address)

# target internal_base_test
