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

# target internal_test
add_library(internal_test
  STATIC
    "fake_clock.cc"
    "fake_single_thread_executor.cc"
    "fake_task_runner.cc"
    "fake_timer.cc"
    "fake_clock.h"
    "fake_device_info.h"
    "fake_single_thread_executor.h"
    "fake_task_runner.h"
    "fake_timer.h"
)

target_link_libraries(internal_test
  PUBLIC
    internal::base::bluetooth_address
    internal::platform::types
    internal::platform::implementation::types
    absl::core_headers
    absl::flat_hash_map
    absl::strings
    absl::synchronization
    absl::time
    absl::span
)

target_include_directories(internal_test PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::test ALIAS internal_test)

# target internal_test_test
