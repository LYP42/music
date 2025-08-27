# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\testm_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\testm_autogen.dir\\ParseCache.txt"
  "testm_autogen"
  )
endif()
