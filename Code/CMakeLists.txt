cmake_minimum_required(VERSION 3.14)
project(LanguageDynamics)

set(CMAKE_CXX_STANDARD 14)
include_directories(/home/rehrev/Documents/Yazilim/C++/eigen-eigen-b3f3d4950030)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DEIGEN_STACK_ALLOCATION_LIMIT=0")
add_executable(DataGenerator DataGenerator/main.cpp Agent.h Agent.cpp Model.h Model.cpp Simulation.cpp Simulation.h LanguageDynamics.cpp LanguageDynamics.h)
add_executable(DataAnalyser DataAnalyser/main.cpp Agent.h Agent.cpp Model.h Model.cpp Simulation.cpp Simulation.h LanguageDynamics.cpp LanguageDynamics.h)