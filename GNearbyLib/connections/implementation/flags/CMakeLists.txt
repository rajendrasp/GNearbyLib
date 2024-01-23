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

# target connections_implementation_flags_connections_flags
add_library(connections_implementation_flags_connections_flags
  INTERFACE
    "nearby_connections_feature_flags.h"
)

target_link_libraries(connections_implementation_flags_connections_flags
  INTERFACE
    internal_flags_flag_reader
    absl::strings
)

target_include_directories(connections_implementation_flags_connections_flags INTERFACE ${CMAKE_SOURCE_DIR})
