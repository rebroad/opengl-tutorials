# OpenGL Tutorials Progress Tracker

## Repository Overview
This repository contains a series of OpenGL tutorials, focusing on teaching various aspects of OpenGL programming. The tutorials appear to be organized into separate directories, each with its own focus.

## Current Setup
- **Environment**: Linux (Ubuntu)
- **Build System**: CMake
- **Dependencies Installed**:
  - libglfw3-dev
  - libglm-dev
  - OpenGL libraries

## Completed Tasks
- [x] Set up GitHub CLI for repository management
- [x] Created a CMakeLists.txt file for building the tutorials
- [x] Successfully compiled and ran the first tutorial ("Create Window")
- [x] Fixed build issues in Tutorials 2, 3, and 4 (added missing cmath header)
- [x] Extended CMakeLists.txt to include Tutorials 2-5
- [x] Extended CMakeLists.txt to include Tutorial 6 (Textures)
- [x] Successfully compiled all tutorials including Tutorial 6
- [x] Extended CMakeLists.txt to include Tutorials 7, 8, 9, and 10
- [x] Successfully compiled Tutorials 7 (Going 3D), 8 (Camera), 9 (Lighting), and 10 (Specular Maps)
- [x] Extended CMakeLists.txt to include Tutorial 11 (Types of Light)
- [x] Successfully compiled Tutorial 11
- [x] Extended CMakeLists.txt to include Tutorial 12 (Mesh Class)
- [x] Successfully compiled Tutorial 12
- [x] Extended CMakeLists.txt to include Tutorial 13 (Model Loading)
- [x] Successfully compiled Tutorial 13
- [x] Extended CMakeLists.txt to include Tutorial 14 (Depth Buffer)
- [x] Successfully compiled Tutorial 14
- [x] Extended CMakeLists.txt to include Tutorial 15 (Stencil Buffer)
- [x] Successfully compiled Tutorial 15
- [x] Extended CMakeLists.txt to include Tutorial 16 (Face Culling & FPS Counter)
- [x] Successfully compiled Tutorial 16
- [x] Extended CMakeLists.txt to include Tutorial 17 (Transparency & Blending)
- [x] Successfully compiled Tutorial 17
## Tutorial Progress

### Tutorial 1 - Create Window
- **Status**: ✅ Compiled and tested successfully
- **Description**: Basic window creation with GLFW and GLAD initialization
- **Core Concepts Covered**:
  - GLFW initialization
  - Window creation
  - GLAD loading
  - Basic rendering loop

### Tutorial 2 - Triangle
- **Status**: ✅ Fixed build error (added missing cmath header)
- **Description**: Drawing a basic triangle with OpenGL
- **Core Concepts Covered**:
  - Vertex Buffer Objects (VBO)
  - Vertex Array Objects (VAO)
  - Drawing primitives
  - Basic rendering

### Tutorial 3 - Indices
- **Status**: ✅ Fixed build error (added missing cmath header)
- **Description**: Using indices for efficient shape rendering
- **Core Concepts Covered**:
  - Element Buffer Objects (EBO)
  - Indexed drawing
  - Efficient vertex reuse

### Tutorial 4 - Organizing
- **Status**: ✅ Fixed build error (added missing cmath header)
- **Description**: Better code organization and structure
- **Core Concepts Covered**:
  - Code organization
  - Shader class implementation
  - VAO and VBO abstractions

### Tutorial 5 - Shaders
- **Status**: ✅ Compiled successfully
- **Description**: Working with GLSL shaders in OpenGL
- **Core Concepts Covered**:
  - GLSL shader language
  - Vertex and fragment shaders
  - Uniform variables

### Tutorial 6 - Textures
- **Status**: ✅ Compiled and tested successfully
- **Description**: Adding textures to OpenGL objects
- **Core Concepts Covered**:
  - Texture loading with stb_image
  - Texture mapping
  - UV coordinates
  - Multiple texture units

### Tutorial 7 - Going 3D
- **Status**: ✅ Compiled successfully
- **Description**: Introduction to 3D rendering in OpenGL
- **Core Concepts Covered**:
  - 3D transformations
  - Perspective projection
  - Z-buffering
  - 3D model coordinates

### Tutorial 8 - Camera
- **Status**: ✅ Compiled successfully
- **Description**: Implementing a camera system in OpenGL
- **Core Concepts Covered**:
  - Camera class implementation
  - View matrix calculation
  - Camera movement (WASD controls)
  - Mouse input for camera rotation
- **Controls**:
  - Keyboard:
    - W: Move forward
    - A: Move left
    - S: Move backward
    - D: Move right
    - SPACE: Move up
    - LEFT CONTROL: Move down
    - LEFT SHIFT (hold): Increase movement speed
  - Mouse:
    - Hold LEFT MOUSE BUTTON: Enter camera rotation mode (mouse movements rotate the camera)

### Tutorial 9 - Lighting
- **Status**: ✅ Compiled successfully
- **Description**: Basic lighting implementation in OpenGL
- **Core Concepts Covered**:
  - Phong lighting model
  - Ambient, diffuse, and specular lighting
  - Material properties
  - Light source positioning

### Tutorial 10 - Specular Maps
- **Status**: ✅ Compiled successfully
- **Description**: Adding specular maps for realistic lighting
- **Core Concepts Covered**:
  - Specular mapping
  - Multiple texture usage
  - Enhanced lighting effects
  - Texture-based material properties

### Tutorial 11 - Types of Light
- **Status**: ✅ Compiled successfully
- **Description**: Implementing different types of light sources
- **Core Concepts Covered**:
  - Directional lights
  - Point lights
  - Spotlights
  - Multiple light sources
  - Light attenuation

### Tutorial 12 - Mesh Class
- **Status**: ✅ Compiled successfully
- **Description**: Implementing a mesh class for better 3D model handling
- **Core Concepts Covered**:
  - Mesh abstraction
  - Vertex data organization
  - Reusable mesh rendering
  - Object-oriented design for 3D models

### Tutorial 13 - Model Loading
- **Status**: ✅ Compiled successfully
- **Description**: Implementing a model loading system for external 3D models
- **Core Concepts Covered**:
  - Assimp library integration
  - 3D model loading from files
  - Model class implementation
  - Handling complex 3D model data

### Tutorial 14 - Depth Buffer
- **Status**: ✅ Compiled successfully
- **Description**: Understanding and working with the depth buffer in OpenGL
- **Core Concepts Covered**:
  - Depth testing
  - Z-buffer visualization
  - Depth buffer configuration
  - Handling object occlusion

### Tutorial 15 - Stencil Buffer
- **Status**: ✅ Compiled successfully
- **Description**: Understanding and working with the stencil buffer in OpenGL
- **Core Concepts Covered**:
  - Stencil testing
  - Object outlining
  - Masking specific objects
  - Stencil buffer configuration

### Tutorial 16 - Face Culling & FPS Counter
- **Status**: ✅ Compiled successfully
- **Description**: Implementing face culling and FPS counter in OpenGL
- **Core Concepts Covered**:
  - Face culling optimization
  - Backface culling
  - Rendering performance metrics
  - FPS (frames per second) counter implementation

### Tutorial 17 - Transparency & Blending
- **Status**: ✅ Compiled successfully
- **Description**: Implementing transparency and blending effects in OpenGL
- **Core Concepts Covered**:
  - Alpha blending
  - Transparency in textures
  - Render order for transparent objects
  - Blending functions and equations

### Remaining Tutorials
The repository includes many more advanced tutorials covering topics such as:
- Additional lighting techniques
- Framebuffers
- HDR and Bloom effects
- And more...

## Build Instructions
To build and run the tutorials:

```bash
# From the repository root
mkdir -p build
cd build
cmake ..
make
./Tutorial1  # Run the first tutorial
```

## Next Steps
- [x] Configure build system for Tutorials 1-5
- [x] Configure build system for Tutorial 6 (Textures)
- [x] Configure build system for the remaining tutorials (7+)
- [ ] Document dependencies for each tutorial
- [ ] Create a consistent naming scheme for built executables
- [ ] Test each tutorial and document its functionality

## Issues and Solutions
- **Missing cmath header**: Tutorials 2, 3, and 4 were missing the `#include <cmath>` header, causing build errors when using the `sqrt()` function. This has been fixed by adding the necessary include directive to each file.
- **Build system**: Successfully created a CMakeLists.txt file that can build Tutorials 1-17.
- **Shader loading**: Enhanced shader file loading mechanism in Tutorials 4 and 5 with fallback paths to search in both current directory and source directory, plus improved error handling and logging for better debugging.
- **Mesh Class**: Fixed a naming conflict in Tutorial 12's Mesh class where a member variable had the same name as its type (renamed VAO to meshVAO).
- **Model Loading**: Fixed the same naming conflict in Tutorial 13's Mesh class (renamed VAO to meshVAO) to ensure successful compilation of the model loading functionality.
- **Depth Buffer**: Fixed the naming conflict in Tutorial 14's Mesh class (renamed VAO to meshVAO) to maintain consistency with previous fixes and ensure successful compilation.
- **Stencil Buffer**: Fixed the naming conflict in Tutorial 15's Mesh class (renamed VAO to meshVAO) to maintain consistency with previous fixes and ensure successful compilation of the stencil buffer functionality.
- **Face Culling & FPS Counter**: Fixed the naming conflict in Tutorial 16's Mesh class (renamed VAO to meshVAO) to maintain consistency with previous fixes and ensure successful compilation of the face culling and FPS counter functionality.
- **Transparency & Blending**: Fixed the naming conflict in Tutorial 17's Mesh class (renamed VAO to meshVAO) to maintain consistency with previous fixes. Also fixed a function signature mismatch in Model.cpp where the Draw function implementation was missing parameters (translation, rotation, and scale) that were declared in the Model.h header.
- **Keyboard Movement Speed in Tutorial 8**: The keyboard movement speed (0.1 units per frame, 0.4 units with SHIFT) is too fast on modern hardware with high frame rates. This makes navigation difficult as pressing the WASD keys causes the camera to move too quickly, while the mouse-based rotation works fine. A potential solution would be to implement frame-rate independent movement by scaling keyboard movement speed with delta time between frames.
