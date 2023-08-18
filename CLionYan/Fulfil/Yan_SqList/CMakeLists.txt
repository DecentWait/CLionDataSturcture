# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Yan_SqList Yan_SqList.h Yan_SqList.c Yan_SqList-main.c)
# 链接公共库
#target_link_libraries(Peng_SqList Scanf_lib)
