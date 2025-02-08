# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ErrorCalculator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ErrorCalculator_autogen.dir/ParseCache.txt"
  "ErrorCalculator_autogen"
  )
endif()
