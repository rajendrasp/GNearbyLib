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

# target credential_cc_proto
protobuf_generate(
  LANGUAGE cpp
  OUT_VAR credential_cc_PROTO_GENERATED
  IMPORT_DIRS
    ${CMAKE_SOURCE_DIR}
  PROTOC_OUT_DIR
    ${CMAKE_BINARY_DIR}
  PROTOS
    "credential.proto"
)

add_library(credential_cc_proto
    ${credential_cc_PROTO_GENERATED}
)

target_include_directories(credential_cc_proto PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(credential_cc_proto PUBLIC protobuf::libprotobuf)

# target local_credential_cc_proto
protobuf_generate(
  LANGUAGE cpp
  OUT_VAR local_credential_cc_PROTO_GENERATED
  IMPORT_DIRS
    ${CMAKE_SOURCE_DIR}
  PROTOC_OUT_DIR
    ${CMAKE_BINARY_DIR}
  PROTOS
    "local_credential.proto"
)

add_library(local_credential_cc_proto
    ${local_credential_cc_PROTO_GENERATED}
)

target_include_directories(local_credential_cc_proto PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(local_credential_cc_proto PUBLIC protobuf::libprotobuf)

# target metadata_cc_proto
protobuf_generate(
  LANGUAGE cpp
  OUT_VAR metadata_cc_PROTO_GENERATED
  IMPORT_DIRS
    ${CMAKE_SOURCE_DIR}
  PROTOC_OUT_DIR
    ${CMAKE_BINARY_DIR}
  PROTOS
    "metadata.proto"
)

add_library(metadata_cc_proto
    ${metadata_cc_PROTO_GENERATED}
)

target_include_directories(metadata_cc_proto PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(metadata_cc_proto PUBLIC protobuf::libprotobuf)

#[[
# target tachyon_cc_proto
protobuf_generate(
  LANGUAGE cpp
  OUT_VAR tachyon_cc_PROTO_GENERATED
  IMPORT_DIRS
    ${CMAKE_SOURCE_DIR}
  PROTOC_OUT_DIR
    ${CMAKE_BINARY_DIR}
  PROTOS
    "duration.proto"
    "ice.proto"
    "tachyon.proto"
    "tachyon_common.proto"
    "tachyon_enums.proto"
)

add_library(tachyon_cc_proto
    ${tachyon_cc_PROTO_GENERATED}
)

target_include_directories(tachyon_cc_proto PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(tachyon_cc_proto PUBLIC protobuf::libprotobuf)
#]]

add_subdirectory("analytics")
