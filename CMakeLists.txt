project(protobuf-test)

cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)
add_subdirectory(protobuf/cmake)

# file(GLOB GENERATED_SRC CONFIGURE_DEPENDS "./generated/*.h" "./generated/*.cpp")
set(GENERATED_SRC "./generated/example.pb.cc" "./generated/example.pb.h")
add_custom_target(compile_protobuf
    COMMAND protobuf/cmake/protoc --cpp_out=${CMAKE_SOURCE_DIR}/generated -I ${CMAKE_SOURCE_DIR} example.proto
    DEPENDS protoc
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
add_executable(test main.cc ${GENERATED_SRC})
add_dependencies(test compile_protobuf)
include_directories(protobuf/src generated)

target_link_libraries(test libprotobuf)
