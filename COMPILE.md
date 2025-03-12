# Compiling the OpenGL Tutorials

This document provides instructions for compiling and running the OpenGL tutorials in this repository.

## Prerequisites

Before you can build the tutorials, you need to have the following dependencies installed:

- **CMake** (3.10 or newer)
- **C++ Compiler** (gcc, clang, or MSVC with C++11 support)
- **GLFW3** - Window management library
- **GLAD** - OpenGL loading library (included in the repository)
- **GLM** - Mathematics library for OpenGL
- **stb_image** - Image loading library (included in the repository)
- **Git** (for repository management)

### Installing Prerequisites on Ubuntu/Debian
```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libglm-dev
```

### Installing Prerequisites on macOS
```bash
brew install cmake glfw glm
```

### Installing Prerequisites on Windows
It's recommended to use vcpkg or pre-built binaries:

```bash
vcpkg install glfw3 glm
```

## Cleaning the Repository

To clean the repository of all build artifacts and start fresh, run:

```bash
git clean -fdx
```

This command removes all untracked files and directories, including build outputs and generated files. **Warning**: This will remove ALL untracked files, so make sure you've committed any work you want to keep.

## Building with CMake

To build all tutorials:

1. Create a build directory and navigate to it:
   ```bash
   cmake -B build
   ```

2. Compile the tutorials:
   ```bash
   cmake --build build -j$(nproc)
   ```
   On Windows, you might use `-j number_of_cores` instead.

## Location of Built Executables

Each tutorial executable is created in its respective tutorial directory:

- Tutorial 1 will be in the "YoutubeOpenGL 1 - Create Window" directory
- Tutorial 2 will be in the "YoutubeOpenGL 2 - Triangle" directory
- And so on for all tutorials

## Running the Tutorials

To run a tutorial, navigate to its directory and execute the binary:

```bash
# For Tutorial 1
cd "YoutubeOpenGL 1 - Create Window"
./Tutorial1

# For Tutorial 2
cd "YoutubeOpenGL 2 - Triangle"
./Tutorial2
```

On Windows, the executables will have a `.exe` extension:

```bash
cd "YoutubeOpenGL 1 - Create Window"
Tutorial1.exe
```

Note: Each tutorial needs to be run from its own directory because they access resource files (shaders, textures, etc.) that are expected to be in the current working directory.

## Troubleshooting

If you encounter any issues:

1. Make sure all prerequisites are installed correctly
2. Try cleaning the build directory and rebuilding:
   ```bash
   rm -rf build
   cmake -B build
   cmake --build build
   ```
3. Check for error messages in the build output

