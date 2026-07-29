cmake_minimum_required(VERSION 3.20)

project(ECSDemo LANGUAGES CXX VERSION 0.1.0)

option(BUILD_TESTING "Build tests" ON)
option(BUILD_BENCHMARKS "Build benchmarks" ON)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(Sanitizers)
include(CompilerWarnings)

# ===== 构建类型，默认Debug =====
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE
        Debug
        CACHE STRING
        "Choose build type"
        FORCE
    )
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# ===== C++ 标准 =====
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ===== 编译选项 =====
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# ===== 库 =====
add_library(ecs STATIC src/dummy.cpp)
target_include_directories(
	ecs
	PUBLIC
	${PROJECT_SOURCE_DIR}/include
)
enable_sanitizers(ecs)
enable_compiler_warnings(ecs)

# ===== 添加测试和性能测试 =====
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

if(BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()