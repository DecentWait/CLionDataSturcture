# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
#add_executable(Peng_SqList Peng_SqList.h Peng_SqList.cpp Peng_SqList-main.cpp ../../Status/Status.cpp)
add_executable(Peng_SqList Peng_SqList.h Peng_SqList.cpp Peng_SqList-main.cpp)
# 链接公共库
#target_link_libraries(Peng_SqList Scanf_lib)
