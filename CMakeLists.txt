cmake_minimum_required(VERSION 3.0.2)
project(base_utils)
set(CMAKE_BUILD_TYPE "debug") #debug release

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)
#############
# LIBRARIES #
#############
aux_source_directory(./src SRC_LIST)
aux_source_directory(./src/ansi_code SRC_LIST)

cs_add_library(${PROJECT_NAME} ${SRC_LIST})
#cs_add_executable(${PROJECT_NAME} ${SRC_LIST})
############
# BINARIES #
############
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
cs_install()
##########
# EXPORT #
##########
cs_export()


