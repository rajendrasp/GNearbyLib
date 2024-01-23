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

# target connections_implementation_analytics_analytics
add_library(connections_implementation_analytics_analytics
    "analytics_recorder.cc"
    "throughput_recorder.cc"
    "analytics_recorder.h"
    "connection_attempt_metadata_params.h"
    "packet_meta_data.h"
    "throughput_recorder.h"
)

target_link_libraries(connections_implementation_analytics_analytics
  PUBLIC
    connections_core_types
    internal_analytics_event_logger
    internal_platform_error_code_recorder
    internal_platform_logging
    internal_platform_types
    internal_platform_implementation_types
    connections_log_cc_proto
    connections_enums_cc_proto
    absl::algorithm_container
    absl::core_headers
    absl::btree
    absl::flat_hash_map
    absl::type_traits
    absl::strings
    absl::str_format
    absl::time
)

target_include_directories(connections_implementation_analytics_analytics PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(connections_implementation_analytics_analytics PRIVATE "CORE_ADAPTER_DLL")

# target connections_implementation_analytics_analytics_test
