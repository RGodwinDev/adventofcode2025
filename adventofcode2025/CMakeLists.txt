# CMakeList.txt : CMake project for adventofcode2025, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (adventofcode2025 
	"adventofcode2025.cpp" "adventofcode2025.h" 
	"Days/Day1/Day1.cpp" "Days/Day1/Day1.h" 
	"Days/Day2/Day2.cpp" "Days/Day2/Day2.h" 
	"Days/Day3/Day3.cpp" "Days/Day3/Day3.h"
	"Days/Day4/Day4.cpp" "Days/Day4/Day4.h"
	"Days/Day5/Day5.cpp" "Days/Day5/Day5.h"
	"Days/Day6/Day6.cpp" "Days/Day6/Day6.h"
	"Days/Day7/Day7.cpp" "Days/Day7/Day7.h"
	"Days/Day8/Day8.cpp" "Days/Day8/Day8.h"
	"Days/Day8/Box.cpp" "Days/Day8/Box.h" 
	"Days/Day8/Circuit.cpp" "Days/Day8/Circuit.h" 
	"Days/Day9/Day9.cpp" "Days/Day9/Day9.h"
	"Days/Day10/Day10.cpp" "Days/Day10/Day10.h"
	"Days/Day10/Joltage.cpp" "Days/Day10/Joltage.h" 
	"Days/Day10/Machine.h" "Days/Day10/Machine.cpp" 
	"Days/Day10/Button.h" "Days/Day10/Button.cpp" 
	"Days/Day11/Day11.cpp" "Days/Day11/Day11.h"
	"Days/Day11/Node.h" "Days/Day11/Node.cpp" 
	"Days/Day11/Path.cpp" "Days/Day11/Path.h" 
	"Days/Day12/Day12.cpp" "Days/Day12/Day12.h"
	"Days/Day12/Shape.cpp" "Days/Day12/Shape.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET adventofcode2025 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# copy input files for binary.
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day1/day1input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day2/day2input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day3/day3input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day4/day4input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day5/day5input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day6/day6input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day7/day7input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day8/day8input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day9/day9input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day10/day10input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day11/day11input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Days/Day12/day12input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)