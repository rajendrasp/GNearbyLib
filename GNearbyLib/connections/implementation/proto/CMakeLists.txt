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


# target offline_wire_formats_cc_proto
protobuf_generate(
  LANGUAGE cpp
  OUT_VAR offline_wire_formats_cc_PROTO_GENERATED
  IMPORT_DIRS
    ${CMAKE_SOURCE_DIR}
  PROTOC_OUT_DIR
    ${CMAKE_BINARY_DIR}
  PROTOS
    "offline_wire_formats.proto"
)

add_library(offline_wire_formats_cc_proto
    ${offline_wire_formats_cc_PROTO_GENERATED}
)

target_include_directories(offline_wire_formats_cc_proto PUBLIC ${CMAKE_BINARY_DIR})
target_link_libraries(offline_wire_formats_cc_proto PUBLIC protobuf::libprotobuf)
