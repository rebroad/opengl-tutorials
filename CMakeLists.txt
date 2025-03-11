cmake_minimum_required(VERSION 3.10)
project(OpenGLTutorials)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
include_directories(${OPENGL_INCLUDE_DIR})
include_directories("YoutubeOpenGL 1 - Create Window/Libraries/include")

# Add glad as a library (common for all tutorials)
add_library(glad
    "YoutubeOpenGL 1 - Create Window/glad.c"
)
target_include_directories(glad PRIVATE
    "YoutubeOpenGL 1 - Create Window/Libraries/include"
)

# Tutorial 1 - Create Window
add_executable(Tutorial1
    "YoutubeOpenGL 1 - Create Window/Main.cpp"
)
target_link_libraries(Tutorial1
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 1 - Create Window"
)
target_include_directories(Tutorial1 PRIVATE
    "YoutubeOpenGL 1 - Create Window"
    "YoutubeOpenGL 1 - Create Window/Libraries/include"
)

# Tutorial 2 - Triangle
add_executable(Tutorial2
    "YoutubeOpenGL 2 - Triangle/Main.cpp"
)
target_link_libraries(Tutorial2
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 2 - Triangle"
)
target_include_directories(Tutorial2 PRIVATE
    "YoutubeOpenGL 2 - Triangle"
    "YoutubeOpenGL 2 - Triangle/Libraries/include"
)

# Tutorial 3 - Indices
add_executable(Tutorial3
    "YoutubeOpenGL 3 - Indices/Main.cpp"
)
target_link_libraries(Tutorial3
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 3 - Indices"
)
target_include_directories(Tutorial3 PRIVATE
    "YoutubeOpenGL 3 - Indices"
    "YoutubeOpenGL 3 - Indices/Libraries/include"
)

# Tutorial 4 - Organizing
add_executable(Tutorial4
    "YoutubeOpenGL 4 - Organizing/Main.cpp"
    "YoutubeOpenGL 4 - Organizing/EBO.cpp"
    "YoutubeOpenGL 4 - Organizing/shaderClass.cpp"
    "YoutubeOpenGL 4 - Organizing/VAO.cpp"
    "YoutubeOpenGL 4 - Organizing/VBO.cpp"
)
target_link_libraries(Tutorial4
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial4 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 4 - Organizing"
)
target_include_directories(Tutorial4 PRIVATE
    "YoutubeOpenGL 4 - Organizing"
    "YoutubeOpenGL 4 - Organizing/Libraries/include"
)

# Tutorial 5 - Shaders
add_executable(Tutorial5
    "YoutubeOpenGL 5 - Shaders/Main.cpp"
    "YoutubeOpenGL 5 - Shaders/EBO.cpp"
    "YoutubeOpenGL 5 - Shaders/shaderClass.cpp"
    "YoutubeOpenGL 5 - Shaders/VAO.cpp"
    "YoutubeOpenGL 5 - Shaders/VBO.cpp"
)
target_link_libraries(Tutorial5
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial5 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 5 - Shaders"
)
target_include_directories(Tutorial5 PRIVATE
    "YoutubeOpenGL 5 - Shaders"
    "YoutubeOpenGL 5 - Shaders/Libraries/include"
)

# Tutorial 6 - Textures
add_executable(Tutorial6
    "YoutubeOpenGL 6 - Textures/Main.cpp"
    "YoutubeOpenGL 6 - Textures/EBO.cpp"
    "YoutubeOpenGL 6 - Textures/shaderClass.cpp"
    "YoutubeOpenGL 6 - Textures/VAO.cpp"
    "YoutubeOpenGL 6 - Textures/VBO.cpp"
    "YoutubeOpenGL 6 - Textures/Texture.cpp"
    "YoutubeOpenGL 6 - Textures/stb.cpp"
)
target_link_libraries(Tutorial6
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial6 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 6 - Textures"
)
target_include_directories(Tutorial6 PRIVATE
    "YoutubeOpenGL 6 - Textures"
    "YoutubeOpenGL 6 - Textures/Libraries/include"
)

# Tutorial 7 - Going 3D
add_executable(Tutorial7
    "YoutubeOpenGL 7 - Going 3D/Main.cpp"
    "YoutubeOpenGL 7 - Going 3D/EBO.cpp"
    "YoutubeOpenGL 7 - Going 3D/shaderClass.cpp"
    "YoutubeOpenGL 7 - Going 3D/VAO.cpp"
    "YoutubeOpenGL 7 - Going 3D/VBO.cpp"
    "YoutubeOpenGL 7 - Going 3D/Texture.cpp"
    "YoutubeOpenGL 7 - Going 3D/stb.cpp"
)
target_link_libraries(Tutorial7
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial7 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 7 - Going 3D"
)
target_include_directories(Tutorial7 PRIVATE
    "YoutubeOpenGL 7 - Going 3D"
    "YoutubeOpenGL 7 - Going 3D/Libraries/include"
)

# Tutorial 8 - Camera
add_executable(Tutorial8
    "YoutubeOpenGL 8 - Camera/Main.cpp"
    "YoutubeOpenGL 8 - Camera/EBO.cpp"
    "YoutubeOpenGL 8 - Camera/shaderClass.cpp"
    "YoutubeOpenGL 8 - Camera/VAO.cpp"
    "YoutubeOpenGL 8 - Camera/VBO.cpp"
    "YoutubeOpenGL 8 - Camera/Texture.cpp"
    "YoutubeOpenGL 8 - Camera/stb.cpp"
    "YoutubeOpenGL 8 - Camera/Camera.cpp"
)
target_link_libraries(Tutorial8
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial8 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 8 - Camera"
)
target_include_directories(Tutorial8 PRIVATE
    "YoutubeOpenGL 8 - Camera"
    "YoutubeOpenGL 8 - Camera/Libraries/include"
)

# Tutorial 9 - Lighting
add_executable(Tutorial9
    "YoutubeOpenGL 9 - Lighting/Main.cpp"
    "YoutubeOpenGL 9 - Lighting/EBO.cpp"
    "YoutubeOpenGL 9 - Lighting/shaderClass.cpp"
    "YoutubeOpenGL 9 - Lighting/VAO.cpp"
    "YoutubeOpenGL 9 - Lighting/VBO.cpp"
    "YoutubeOpenGL 9 - Lighting/Texture.cpp"
    "YoutubeOpenGL 9 - Lighting/stb.cpp"
    "YoutubeOpenGL 9 - Lighting/Camera.cpp"
)
target_link_libraries(Tutorial9
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial9 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 9 - Lighting"
)
target_include_directories(Tutorial9 PRIVATE
    "YoutubeOpenGL 9 - Lighting"
    "YoutubeOpenGL 9 - Lighting/Libraries/include"
)

# Tutorial 10 - Specular Maps
add_executable(Tutorial10
    "YoutubeOpenGL 10 - Specular Maps/Main.cpp"
    "YoutubeOpenGL 10 - Specular Maps/EBO.cpp"
    "YoutubeOpenGL 10 - Specular Maps/shaderClass.cpp"
    "YoutubeOpenGL 10 - Specular Maps/VAO.cpp"
    "YoutubeOpenGL 10 - Specular Maps/VBO.cpp"
    "YoutubeOpenGL 10 - Specular Maps/Texture.cpp"
    "YoutubeOpenGL 10 - Specular Maps/stb.cpp"
    "YoutubeOpenGL 10 - Specular Maps/Camera.cpp"
)
target_link_libraries(Tutorial10
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial10 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 10 - Specular Maps"
)
target_include_directories(Tutorial10 PRIVATE
    "YoutubeOpenGL 10 - Specular Maps"
    "YoutubeOpenGL 10 - Specular Maps/Libraries/include"
)

# Tutorial 11 - Types of Light
add_executable(Tutorial11
    "YoutubeOpenGL 11 - Types of Light/Main.cpp"
    "YoutubeOpenGL 11 - Types of Light/EBO.cpp"
    "YoutubeOpenGL 11 - Types of Light/shaderClass.cpp"
    "YoutubeOpenGL 11 - Types of Light/VAO.cpp"
    "YoutubeOpenGL 11 - Types of Light/VBO.cpp"
    "YoutubeOpenGL 11 - Types of Light/Texture.cpp"
    "YoutubeOpenGL 11 - Types of Light/stb.cpp"
    "YoutubeOpenGL 11 - Types of Light/Camera.cpp"
)
target_link_libraries(Tutorial11
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial11 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 11 - Types of Light"
)
target_include_directories(Tutorial11 PRIVATE
    "YoutubeOpenGL 11 - Types of Light"
    "YoutubeOpenGL 11 - Types of Light/Libraries/include"
)

# Tutorial 12 - Mesh Class
add_executable(Tutorial12
    "YoutubeOpenGL 12 - Mesh Class/Main.cpp"
    "YoutubeOpenGL 12 - Mesh Class/EBO.cpp"
    "YoutubeOpenGL 12 - Mesh Class/shaderClass.cpp"
    "YoutubeOpenGL 12 - Mesh Class/VAO.cpp"
    "YoutubeOpenGL 12 - Mesh Class/VBO.cpp"
    "YoutubeOpenGL 12 - Mesh Class/Texture.cpp"
    "YoutubeOpenGL 12 - Mesh Class/stb.cpp"
    "YoutubeOpenGL 12 - Mesh Class/Camera.cpp"
    "YoutubeOpenGL 12 - Mesh Class/Mesh.cpp"
)
target_link_libraries(Tutorial12
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial12 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 12 - Mesh Class"
)
target_include_directories(Tutorial12 PRIVATE
    "YoutubeOpenGL 12 - Mesh Class"
    "YoutubeOpenGL 12 - Mesh Class/Libraries/include"
)

# Tutorial 13 - Model Loading
add_executable(Tutorial13
    "YoutubeOpenGL 13 - Model Loading/Main.cpp"
    "YoutubeOpenGL 13 - Model Loading/EBO.cpp"
    "YoutubeOpenGL 13 - Model Loading/shaderClass.cpp"
    "YoutubeOpenGL 13 - Model Loading/VAO.cpp"
    "YoutubeOpenGL 13 - Model Loading/VBO.cpp"
    "YoutubeOpenGL 13 - Model Loading/Texture.cpp"
    "YoutubeOpenGL 13 - Model Loading/stb.cpp"
    "YoutubeOpenGL 13 - Model Loading/Camera.cpp"
    "YoutubeOpenGL 13 - Model Loading/Mesh.cpp"
    "YoutubeOpenGL 13 - Model Loading/Model.cpp"
)
target_link_libraries(Tutorial13
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial13 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 13 - Model Loading"
)
target_include_directories(Tutorial13 PRIVATE
    "YoutubeOpenGL 13 - Model Loading"
    "YoutubeOpenGL 13 - Model Loading/Libraries/include"
)

# Tutorial 14 - Depth Buffer
add_executable(Tutorial14
    "YoutubeOpenGL 14 - Depth Buffer/Main.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/EBO.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/shaderClass.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/VAO.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/VBO.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/Texture.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/stb.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/Camera.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/Mesh.cpp"
    "YoutubeOpenGL 14 - Depth Buffer/Model.cpp"
)
target_link_libraries(Tutorial14
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial14 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 14 - Depth Buffer"
)
target_include_directories(Tutorial14 PRIVATE
    "YoutubeOpenGL 14 - Depth Buffer"
    "YoutubeOpenGL 14 - Depth Buffer/Libraries/include"
)

# Tutorial 15 - Stencil Buffer
add_executable(Tutorial15
    "YoutubeOpenGL 15 - Stencil Buffer/Main.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/EBO.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/shaderClass.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/VAO.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/VBO.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/Texture.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/stb.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/Camera.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/Mesh.cpp"
    "YoutubeOpenGL 15 - Stencil Buffer/Model.cpp"
)
target_link_libraries(Tutorial15
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial15 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 15 - Stencil Buffer"
)
target_include_directories(Tutorial15 PRIVATE
    "YoutubeOpenGL 15 - Stencil Buffer"
    "YoutubeOpenGL 15 - Stencil Buffer/Libraries/include"
)

# Tutorial 16 - Face Culling & FPS Counter
add_executable(Tutorial16
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Main.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/EBO.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/shaderClass.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/VAO.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/VBO.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Texture.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/stb.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Camera.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Mesh.cpp"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Model.cpp"
)
target_link_libraries(Tutorial16
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial16 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 16 - Face Culling & FPS Counter"
)
target_include_directories(Tutorial16 PRIVATE
    "YoutubeOpenGL 16 - Face Culling & FPS Counter"
    "YoutubeOpenGL 16 - Face Culling & FPS Counter/Libraries/include"
)

# Tutorial 17 - Transparency & Blending
add_executable(Tutorial17
    "YoutubeOpenGL 17 - Transparency & Blending/Main.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/EBO.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/shaderClass.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/VAO.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/VBO.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/Texture.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/stb.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/Camera.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/Mesh.cpp"
    "YoutubeOpenGL 17 - Transparency & Blending/Model.cpp"
)
target_link_libraries(Tutorial17
    glad
    ${OPENGL_LIBRARIES}
    glfw
)
set_target_properties(Tutorial17 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/YoutubeOpenGL 17 - Transparency & Blending"
)
target_include_directories(Tutorial17 PRIVATE
    "YoutubeOpenGL 17 - Transparency & Blending"
    "YoutubeOpenGL 17 - Transparency & Blending/Libraries/include"
)

# Build instructions
message(STATUS "")
message(STATUS "-- OpenGL Tutorials Build Configuration --")
message(STATUS "")
message(STATUS "Build all tutorials with:")
message(STATUS "  mkdir -p build && cd build && cmake .. && make")
message(STATUS "")
message(STATUS "Executables will be created in their respective tutorial directories.")
message(STATUS "Run each tutorial by navigating to its directory and running the executable.")
message(STATUS "")
message(STATUS "For example, to run Tutorial 1:")
message(STATUS "  cd '../YoutubeOpenGL 1 - Create Window' && ./Tutorial1")
message(STATUS "")
message(STATUS "Similarly for other tutorials:")
message(STATUS "  cd '../YoutubeOpenGL 2 - Triangle' && ./Tutorial2")
message(STATUS "  cd '../YoutubeOpenGL 3 - Indices' && ./Tutorial3")
message(STATUS "  cd '../YoutubeOpenGL 4 - Organizing' && ./Tutorial4")
message(STATUS "  cd '../YoutubeOpenGL 5 - Shaders' && ./Tutorial5")
message(STATUS "  cd '../YoutubeOpenGL 6 - Textures' && ./Tutorial6")
message(STATUS "  cd '../YoutubeOpenGL 7 - Going 3D' && ./Tutorial7")
message(STATUS "  cd '../YoutubeOpenGL 8 - Camera' && ./Tutorial8")
message(STATUS "  cd '../YoutubeOpenGL 9 - Lighting' && ./Tutorial9")
message(STATUS "  cd '../YoutubeOpenGL 10 - Specular Maps' && ./Tutorial10")
message(STATUS "  cd '../YoutubeOpenGL 11 - Types of Light' && ./Tutorial11")
message(STATUS "  cd '../YoutubeOpenGL 12 - Mesh Class' && ./Tutorial12")
message(STATUS "  cd '../YoutubeOpenGL 13 - Model Loading' && ./Tutorial13")
message(STATUS "  cd '../YoutubeOpenGL 14 - Depth Buffer' && ./Tutorial14")
message(STATUS "  cd '../YoutubeOpenGL 15 - Stencil Buffer' && ./Tutorial15")
message(STATUS "  cd '../YoutubeOpenGL 16 - Face Culling & FPS Counter' && ./Tutorial16")
message(STATUS "  cd '../YoutubeOpenGL 17 - Transparency & Blending' && ./Tutorial17")
message(STATUS "")
