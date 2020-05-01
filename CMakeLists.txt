# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( prison_interpreter )

# flags
add_definitions( "-g" )

# files

# include
include_directories( ./include ./src )

# target
file(GLOB SRC "src/*cpp")
add_executable( prison ${SRC} )
