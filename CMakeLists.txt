# cmake最低版本
cmake_minimum_required(VERSION 3.15)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(spdlog_easy)

# 生成執行文件
add_executable(main "")

target_sources(main 
	PRIVATE
        src/main.cpp
        include/spdlog_easy.hpp
)

set_target_properties(main PROPERTIES DEBUG_POSTFIX "_debug")

add_definitions(/W4 /MP)

# 頭文件目錄
target_include_directories(main
	PRIVATE
        third/spdlog/include
        include
)

# target_link_directories(main
#     PRIVATE
#         C:/local/boost_1_70_0/lib64-msvc-14.2
# )

# target_link_libraries(main
#     libboost_date_time-vc142-mt-gd-x64-1_70
# )
