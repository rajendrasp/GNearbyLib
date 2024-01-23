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

# target internal_platform_flags_platform_flags
add_library(internal_platform_flags_platform_flags
  INTERFACE
    "nearby_platform_feature_flags.h"
)

target_link_libraries(internal_platform_flags_platform_flags
  INTERFACE
    internal::flags::flag_reader
    absl::strings
)

target_include_directories(internal_platform_flags_platform_flags INTERFACE ${CMAKE_SOURCE_DIR})

add_library(internal::platform::flags::platform_flags ALIAS internal_platform_flags_platform_flags)
