# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rehrev/Documents/Okul/LanguageDynamics/Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataAnalyser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataAnalyser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataAnalyser.dir/flags.make

CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o: CMakeFiles/DataAnalyser.dir/flags.make
CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o: ../DataAnalyser/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o -c /home/rehrev/Documents/Okul/LanguageDynamics/Code/DataAnalyser/main.cpp

CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehrev/Documents/Okul/LanguageDynamics/Code/DataAnalyser/main.cpp > CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.i

CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehrev/Documents/Okul/LanguageDynamics/Code/DataAnalyser/main.cpp -o CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.s

CMakeFiles/DataAnalyser.dir/Agent.cpp.o: CMakeFiles/DataAnalyser.dir/flags.make
CMakeFiles/DataAnalyser.dir/Agent.cpp.o: ../Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DataAnalyser.dir/Agent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataAnalyser.dir/Agent.cpp.o -c /home/rehrev/Documents/Okul/LanguageDynamics/Code/Agent.cpp

CMakeFiles/DataAnalyser.dir/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataAnalyser.dir/Agent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehrev/Documents/Okul/LanguageDynamics/Code/Agent.cpp > CMakeFiles/DataAnalyser.dir/Agent.cpp.i

CMakeFiles/DataAnalyser.dir/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataAnalyser.dir/Agent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehrev/Documents/Okul/LanguageDynamics/Code/Agent.cpp -o CMakeFiles/DataAnalyser.dir/Agent.cpp.s

CMakeFiles/DataAnalyser.dir/Model.cpp.o: CMakeFiles/DataAnalyser.dir/flags.make
CMakeFiles/DataAnalyser.dir/Model.cpp.o: ../Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DataAnalyser.dir/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataAnalyser.dir/Model.cpp.o -c /home/rehrev/Documents/Okul/LanguageDynamics/Code/Model.cpp

CMakeFiles/DataAnalyser.dir/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataAnalyser.dir/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehrev/Documents/Okul/LanguageDynamics/Code/Model.cpp > CMakeFiles/DataAnalyser.dir/Model.cpp.i

CMakeFiles/DataAnalyser.dir/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataAnalyser.dir/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehrev/Documents/Okul/LanguageDynamics/Code/Model.cpp -o CMakeFiles/DataAnalyser.dir/Model.cpp.s

CMakeFiles/DataAnalyser.dir/Simulation.cpp.o: CMakeFiles/DataAnalyser.dir/flags.make
CMakeFiles/DataAnalyser.dir/Simulation.cpp.o: ../Simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DataAnalyser.dir/Simulation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataAnalyser.dir/Simulation.cpp.o -c /home/rehrev/Documents/Okul/LanguageDynamics/Code/Simulation.cpp

CMakeFiles/DataAnalyser.dir/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataAnalyser.dir/Simulation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehrev/Documents/Okul/LanguageDynamics/Code/Simulation.cpp > CMakeFiles/DataAnalyser.dir/Simulation.cpp.i

CMakeFiles/DataAnalyser.dir/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataAnalyser.dir/Simulation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehrev/Documents/Okul/LanguageDynamics/Code/Simulation.cpp -o CMakeFiles/DataAnalyser.dir/Simulation.cpp.s

CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o: CMakeFiles/DataAnalyser.dir/flags.make
CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o: ../LanguageDynamics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o -c /home/rehrev/Documents/Okul/LanguageDynamics/Code/LanguageDynamics.cpp

CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rehrev/Documents/Okul/LanguageDynamics/Code/LanguageDynamics.cpp > CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.i

CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rehrev/Documents/Okul/LanguageDynamics/Code/LanguageDynamics.cpp -o CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.s

# Object files for target DataAnalyser
DataAnalyser_OBJECTS = \
"CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o" \
"CMakeFiles/DataAnalyser.dir/Agent.cpp.o" \
"CMakeFiles/DataAnalyser.dir/Model.cpp.o" \
"CMakeFiles/DataAnalyser.dir/Simulation.cpp.o" \
"CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o"

# External object files for target DataAnalyser
DataAnalyser_EXTERNAL_OBJECTS =

DataAnalyser: CMakeFiles/DataAnalyser.dir/DataAnalyser/main.cpp.o
DataAnalyser: CMakeFiles/DataAnalyser.dir/Agent.cpp.o
DataAnalyser: CMakeFiles/DataAnalyser.dir/Model.cpp.o
DataAnalyser: CMakeFiles/DataAnalyser.dir/Simulation.cpp.o
DataAnalyser: CMakeFiles/DataAnalyser.dir/LanguageDynamics.cpp.o
DataAnalyser: CMakeFiles/DataAnalyser.dir/build.make
DataAnalyser: CMakeFiles/DataAnalyser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable DataAnalyser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataAnalyser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataAnalyser.dir/build: DataAnalyser

.PHONY : CMakeFiles/DataAnalyser.dir/build

CMakeFiles/DataAnalyser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataAnalyser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataAnalyser.dir/clean

CMakeFiles/DataAnalyser.dir/depend:
	cd /home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rehrev/Documents/Okul/LanguageDynamics/Code /home/rehrev/Documents/Okul/LanguageDynamics/Code /home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug /home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug /home/rehrev/Documents/Okul/LanguageDynamics/Code/cmake-build-debug/CMakeFiles/DataAnalyser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataAnalyser.dir/depend

