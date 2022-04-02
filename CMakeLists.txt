cmake_minimum_required(VERSION 3.5)

set(VCPKG_MANIFEST_DIR ${CMAKE_SOURCE_DIR}/vcpkg)

project(my_linux_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "my_linux_test/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

file(GLOB SOURCES_RAW "my_linux_raw_test/*.cpp")

add_executable(${PROJECT_NAME}_RAW ${SOURCES_RAW})

find_path(LOERR_INCLUDE_DIRS "loerr/loerr-detail.h")

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/my_linux_test
        ${LOERR_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME}_RAW
    PRIVATE
        ${PROJECT_SOURCE_DIR}/my_linux_raw_test
        ${LOERR_INCLUDE_DIRS}
)