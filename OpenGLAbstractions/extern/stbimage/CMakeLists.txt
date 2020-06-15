project("stbimage")

add_library(stbimage "stb_image.cpp")
target_include_directories(stbimage PUBLIC "./")