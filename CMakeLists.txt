# cmake最低版本
cmake_minimum_required(VERSION 3.16)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(spdlog_easy)

# 生成執行文件
add_executable(main "")

set(SPDLOG_EASY_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SPDLOG_EASY)
if(SPDLOG_EASY_FOUND)
    cmake_print_variables(SPDLOG_EASY_INCLUDE_DIR)
endif()

target_sources(main 
	PRIVATE
        src/main.cpp
)

set_target_properties(main PROPERTIES DEBUG_POSTFIX "_debug")

add_definitions(/W4 /MP)

# 頭文件目錄
target_include_directories(main
	PRIVATE
        ${SPDLOG_EASY_INCLUDE_DIR}
)
