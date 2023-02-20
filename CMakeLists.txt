cmake_minimum_required(VERSION 3.4...3.18)
project(pyfgt)

add_subdirectory(pybind11)
link_directories(${Python_LIBRARY_DIRS})
link_libraries(${Python_LIBRARIES})
include_directories(${pybind11_INCLUDE_DIRS})
link_libraries(${pybind11_LIBRARIES})
  
add_library(pyfgt MODULE
  src/main.cpp
)

if(APPLE)
  target_link_options(pyfgt PUBLIC -undefined dynamic_lookup)
endif(APPLE)

target_link_libraries(pyfgt
  PRIVATE pybind11::headers
)
pybind11_extension(pyfgt)

add_subdirectory(fgt)
# find_package(Fgt REQUIRED)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pyfgt
  PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO}
)
target_include_directories(pyfgt PUBLIC
  fgt/include
)
target_link_libraries(pyfgt
  PRIVATE Library-C++
)
