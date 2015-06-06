project(3DGameEngine)
cmake_minimum_required(VERSION 2.8)

# add the -c and -Wall flags
add_definitions(
        -c
        -Wall
)

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Lets LOAD app our headers!
file(GLOB_RECURSE HDRS ${3DGameEngine_SOURCE_DIR}/src/*.h)

# Lets LOAD app our sources!
file(GLOB_RECURSE SRCS ${3DGameEngine_SOURCE_DIR}/src/*.cpp)

find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

find_package(OpenGL)
include_directories(${OPENGL_INCLUDE_DIR})

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HDRS} ${SRCS})

link_libraries(${OPENGL_gl_LIBRARY} ${MATH_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLFW_STATIC_LIBRARIES} ${OPENGL_LIBRARIES})


