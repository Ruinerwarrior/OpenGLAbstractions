# CMakeList.txt : CMake project for OpenGLAbstractions, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/OpenGLAbstractions/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/OpenGLAbstractions/includes")
set(EXTERN_DIR "${PROJECT_SOURCE_DIR}/OpenGLAbstractions/extern")

list (APPEND SOURCE_FILES
	"${SRC_DIR}/glad.c"
	"${SRC_DIR}/VertexBuffer.cpp"
	"${SRC_DIR}/IndexBuffer.cpp"
	"${SRC_DIR}/VertexArray.cpp"
	"${SRC_DIR}/Texture.cpp"
	"${SRC_DIR}/Shader.cpp"
)


# Add source to this project's library.
add_library(OpenGLAbstractions ${SOURCE_FILES})

target_include_directories(OpenGLAbstractions INTERFACE ${INCLUDE_DIR})
target_include_directories(OpenGLAbstractions PRIVATE "${INCLUDE_DIR}/glad")

# Add dependencies

#----------------------------------------------
# ADD OPENGL LIBRARY DEPENDENCY
#----------------------------------------------
find_package(OpenGL REQUIRED)
target_link_libraries(OpenGLAbstractions ${OpenGL})

#----------------------------------------------
# ADD STB_IMAGE LIBRARY DEPENDENCY
#----------------------------------------------
add_library("stb_image" "${EXTERN_DIR}/stbimage/stb_image.cpp")
target_include_directories("stb_image" PRIVATE "${EXTERN_DIR}/stb_image")
target_include_directories(OpenGLAbstractions PUBLIC "${EXTERN_DIR}/stb_image")
target_link_libraries(OpenGLAbstractions "stb_image" "${CMAKE_DL_LIBS}")

#---------------------------------------------
# ADD GLM LIBRARY DEPENDENCY
# --------------------------------------------
add_subdirectory("${EXTERN_DIR}/glm")
target_include_directories(OpenGLAbstractions PRIVATE "${EXTERN_DIR}")
