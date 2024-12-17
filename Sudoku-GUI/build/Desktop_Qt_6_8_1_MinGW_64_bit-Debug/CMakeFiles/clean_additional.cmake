# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Sudoku-GUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Sudoku-GUI_autogen.dir\\ParseCache.txt"
  "Sudoku-GUI_autogen"
  )
endif()
