# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\Num_Conv_Cpp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Num_Conv_Cpp_autogen.dir\\ParseCache.txt"
  "Num_Conv_Cpp_autogen"
  )
endif()
