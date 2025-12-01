# CMakeList.txt : CMake project for adventofcode2025, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (adventofcode2025 "adventofcode2025.cpp" "adventofcode2025.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET adventofcode2025 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
