# cmake version to be used
cmake_minimum_required( VERSION 3.0 )
set(CMAKE_CXX_STANDARD 11)

# project name
project( prison_interpreter )

# flags
add_definitions( "-g" )

set(CMAKE_BUILD_TYPE Debug)

# files

# include
include_directories( ./include ./src )

# target
file(GLOB_RECURSE SRC "src/*cpp")
add_executable( prison ${SRC} )
