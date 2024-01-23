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

# target internal_crypto
add_library(internal_crypto
  "ed25519.cc"
  "ed25519.h"
)

target_link_libraries(internal_crypto
  PUBLIC
    internal::crypto_cros
    boringssl::crypto
    absl::status
    absl::statusor
    absl::str_format
    absl::optional
    absl::span
)

target_include_directories(internal_crypto PRIVATE ${CMAKE_SOURCE_DIR})

add_library(internal::crypto ALIAS internal_crypto)

# target internal_crypto_unittests
