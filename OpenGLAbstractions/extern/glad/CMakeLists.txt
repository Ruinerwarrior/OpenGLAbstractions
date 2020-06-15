project("glad")

add_library(glad "glad.c")
target_include_directories(glad PUBLIC "./")