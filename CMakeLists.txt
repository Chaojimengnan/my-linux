cmake_minimum_required(VERSION 3.5)

project(my_linux_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "my_linux_test/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

file(GLOB SOURCES_RAW "my_linux_raw_test/*.cpp")

add_executable(${PROJECT_NAME}_RAW ${SOURCES_RAW})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/my_linux_test
)

target_include_directories(${PROJECT_NAME}_RAW
    PRIVATE
        ${PROJECT_SOURCE_DIR}/my_linux_raw_test
)