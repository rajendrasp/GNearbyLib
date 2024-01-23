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

# target internal_crypto_cros
add_library(internal_crypto_cros
    "aead.cc"
    "ec_private_key.cc"
    "ec_signature_creator.cc"
    "ec_signature_creator_impl.cc"
    "encryptor.cc"
    "hkdf.cc"
    "hmac.cc"
    "nearby_base.cc"
    "openssl_util.cc"
    "random.cc"
    "rsa_private_key.cc"
    "secure_hash.cc"
    "secure_util.cc"
    "sha2.cc"
    "signature_verifier.cc"
    "symmetric_key.cc"
    "aead.h"
    "crypto_export.h"
    "ec_private_key.h"
    "ec_signature_creator.h"
    "ec_signature_creator_impl.h"
    "encryptor.h"
    "hkdf.h"
    "hmac.h"
    "nearby_base.h"
    "openssl_util.h"
    "random.h"
    "rsa_private_key.h"
    "secure_hash.h"
    "secure_util.h"
    "sha2.h"
    "signature_verifier.h"
    "symmetric_key.h"
)

target_link_libraries(internal_crypto_cros
  PUBLIC
    boringssl::crypto
    absl::core_headers
    absl::log
    absl::check
    absl::status
    absl::statusor
    absl::strings
    absl::str_format
    absl::optional
    absl::span
)

target_include_directories(internal_crypto_cros PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_definitions(internal_crypto_cros PRIVATE CRYPTO_IMPLEMENTATION)

add_library(internal::crypto_cros ALIAS internal_crypto_cros)

# target internal_crypto_cros_unittests
