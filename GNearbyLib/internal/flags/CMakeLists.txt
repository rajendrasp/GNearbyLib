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

# target internal_flags_flag_reader
add_library(internal_flags_flag_reader
  INTERFACE
    "default_flag_reader.h"
    "flag.h"
    "flag_reader.h"
)

target_link_libraries(internal_flags_flag_reader
  INTERFACE
    absl::strings
)

target_include_directories(internal_flags_flag_reader INTERFACE ${CMAKE_SOURCE_DIR})

add_library(internal::flags::flag_reader ALIAS internal_flags_flag_reader)

# target internal_flags_nearby_flags
add_library(internal_flags_nearby_flags
    "nearby_flags.cc"
    "nearby_flags.h"
)

target_link_libraries(internal_flags_nearby_flags
  PUBLIC
    internal::flags::flag_reader
    internal::platform::types
    absl::core_headers
    absl::flat_hash_map
    absl::strings
    absl::synchronization
)

target_include_directories(internal_flags_nearby_flags PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::flags::nearby_flags ALIAS internal_flags_nearby_flags)

# target internal_flags_nearby_flags_test
