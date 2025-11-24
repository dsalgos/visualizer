cmake_minimum_required(VERSION 3.10)
project(visualizer CXX)

# Require C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For installing external libraries
include(FetchContent)

##################################
#     INTERNAL DEPENDENCY        #
##################################

FetchContent_Declare(
  dsalgos
  GIT_REPOSITORY https://github.com/dsalgos/dsalgos.git
  GIT_TAG main
)

FetchContent_MakeAvailable(dsalgos)


##################################
#       EXTERNAL DEPENDENCIES    #
##################################

# FTXUI
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(ftxui)

#################################
#     BUILD THE EXECUTABLE      #
#################################

add_executable(visualizer src/main.cpp src/menu/menu.cpp)
target_include_directories(visualizer PRIVATE src)
target_link_libraries(visualizer PRIVATE dsalgos)
target_link_libraries(visualizer PRIVATE ftxui::screen ftxui::dom ftxui::component)