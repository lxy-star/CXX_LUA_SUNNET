# 项目名称
project (sunnet)

# CMAKE最低版本
cmake_minimum_required (VERSION 3.0)

# 头文件目录
include_directories (include)

# 查找./src下所有源文件并把这些文件赋值给DIR_SRCS变量中
aux_source_directory (./src DIR_SRCS)
# 添加库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd/lua-5.4.6/src/)
# 指定c++版本
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成指定文件
add_executable (sunnet ${DIR_SRCS})

# 查找库文件
find_package (Threads)
target_link_libraries (sunnet ${CMAKE_THREAD_LIBS_INIT})
#lua头文件、库
include_directories(./3rd/lua-5.4.6/src)
target_link_libraries(sunnet liblua.a)
target_link_libraries(sunnet dl)