#!/bin/bash
# Script to compile the OpenGL tutorials
# Usage: ./compile.sh [--clean]
#   --clean: Removes all untracked files before building (git clean -fdx)

set -e  # Exit immediately if a command exits with a non-zero status

# Print with color
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Function to print status messages
print_status() {
    echo -e "${GREEN}[COMPILE]${NC} $1"
}

# Function to print error messages
print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to print warning messages
print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

# Check for --clean parameter
if [ "$1" = "--clean" ]; then
    print_status "Cleaning repository (removing all untracked files)..."
    if git clean -fdx; then
        print_status "Repository cleaned successfully."
    else
        print_error "Failed to clean repository."
        exit 1
    fi
fi

# Create build directory if it doesn't exist
print_status "Creating build directory..."
if [ ! -d "build" ]; then
    mkdir -p build
    if [ $? -ne 0 ]; then
        print_error "Failed to create build directory."
        exit 1
    fi
fi

# Run CMake
print_status "Running CMake..."
cd build
if cmake ..; then
    print_status "CMake configuration complete."
else
    print_error "CMake configuration failed."
    exit 1
fi

# Determine the number of CPU cores for parallel build
if [ -f /proc/cpuinfo ]; then
    # Linux
    CPU_CORES=$(grep -c ^processor /proc/cpuinfo)
elif [ "$(uname)" = "Darwin" ]; then
    # macOS
    CPU_CORES=$(sysctl -n hw.ncpu)
else
    # Default to 2 cores if we can't determine
    CPU_CORES=2
fi
print_status "Using $CPU_CORES CPU cores for build..."

# Build the project
print_status "Building project..."
if make -j"$CPU_CORES"; then
    print_status "Build completed successfully!"
    print_status "Executables are located in their respective tutorial directories."
    print_status "Example: cd 'YoutubeOpenGL 1 - Create Window' && ./Tutorial1"
else
    print_error "Build failed."
    exit 1
fi

cd ..
print_status "All done!"

