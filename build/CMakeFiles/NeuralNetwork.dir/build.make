# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/Desktop/Learning/NeuralNetworks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/Desktop/Learning/NeuralNetworks/build

# Include any dependencies generated for this target.
include CMakeFiles/NeuralNetwork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NeuralNetwork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NeuralNetwork.dir/flags.make

CMakeFiles/NeuralNetwork.dir/main.cpp.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NeuralNetwork.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NeuralNetwork.dir/main.cpp.o -c /home/ben/Desktop/Learning/NeuralNetworks/main.cpp

CMakeFiles/NeuralNetwork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NeuralNetwork.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Learning/NeuralNetworks/main.cpp > CMakeFiles/NeuralNetwork.dir/main.cpp.i

CMakeFiles/NeuralNetwork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NeuralNetwork.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Learning/NeuralNetworks/main.cpp -o CMakeFiles/NeuralNetwork.dir/main.cpp.s

CMakeFiles/NeuralNetwork.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/main.cpp.o.requires

CMakeFiles/NeuralNetwork.dir/main.cpp.o.provides: CMakeFiles/NeuralNetwork.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/main.cpp.o.provides

CMakeFiles/NeuralNetwork.dir/main.cpp.o.provides.build: CMakeFiles/NeuralNetwork.dir/main.cpp.o


CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o: ../src/Network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o -c /home/ben/Desktop/Learning/NeuralNetworks/src/Network.cpp

CMakeFiles/NeuralNetwork.dir/src/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NeuralNetwork.dir/src/Network.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Learning/NeuralNetworks/src/Network.cpp > CMakeFiles/NeuralNetwork.dir/src/Network.cpp.i

CMakeFiles/NeuralNetwork.dir/src/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NeuralNetwork.dir/src/Network.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Learning/NeuralNetworks/src/Network.cpp -o CMakeFiles/NeuralNetwork.dir/src/Network.cpp.s

CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.requires

CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.provides: CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.provides

CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.provides.build: CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o


CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o: ../src/Propagation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o -c /home/ben/Desktop/Learning/NeuralNetworks/src/Propagation.cpp

CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Learning/NeuralNetworks/src/Propagation.cpp > CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.i

CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Learning/NeuralNetworks/src/Propagation.cpp -o CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.s

CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.requires

CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.provides: CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.provides

CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.provides.build: CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o


CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o: ../src/BackPropagation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o -c /home/ben/Desktop/Learning/NeuralNetworks/src/BackPropagation.cpp

CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Learning/NeuralNetworks/src/BackPropagation.cpp > CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.i

CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Learning/NeuralNetworks/src/BackPropagation.cpp -o CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.s

CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.requires

CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.provides: CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.provides

CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.provides.build: CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o


CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o: CMakeFiles/NeuralNetwork.dir/flags.make
CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o: ../src/Drone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o -c /home/ben/Desktop/Learning/NeuralNetworks/src/Drone.cpp

CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Desktop/Learning/NeuralNetworks/src/Drone.cpp > CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.i

CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Desktop/Learning/NeuralNetworks/src/Drone.cpp -o CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.s

CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.requires:

.PHONY : CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.requires

CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.provides: CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.requires
	$(MAKE) -f CMakeFiles/NeuralNetwork.dir/build.make CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.provides.build
.PHONY : CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.provides

CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.provides.build: CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o


# Object files for target NeuralNetwork
NeuralNetwork_OBJECTS = \
"CMakeFiles/NeuralNetwork.dir/main.cpp.o" \
"CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o" \
"CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o" \
"CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o" \
"CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o"

# External object files for target NeuralNetwork
NeuralNetwork_EXTERNAL_OBJECTS =

NeuralNetwork: CMakeFiles/NeuralNetwork.dir/main.cpp.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/build.make
NeuralNetwork: CMakeFiles/NeuralNetwork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable NeuralNetwork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NeuralNetwork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NeuralNetwork.dir/build: NeuralNetwork

.PHONY : CMakeFiles/NeuralNetwork.dir/build

CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/main.cpp.o.requires
CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/src/Network.cpp.o.requires
CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/src/Propagation.cpp.o.requires
CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/src/BackPropagation.cpp.o.requires
CMakeFiles/NeuralNetwork.dir/requires: CMakeFiles/NeuralNetwork.dir/src/Drone.cpp.o.requires

.PHONY : CMakeFiles/NeuralNetwork.dir/requires

CMakeFiles/NeuralNetwork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NeuralNetwork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NeuralNetwork.dir/clean

CMakeFiles/NeuralNetwork.dir/depend:
	cd /home/ben/Desktop/Learning/NeuralNetworks/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/Desktop/Learning/NeuralNetworks /home/ben/Desktop/Learning/NeuralNetworks /home/ben/Desktop/Learning/NeuralNetworks/build /home/ben/Desktop/Learning/NeuralNetworks/build /home/ben/Desktop/Learning/NeuralNetworks/build/CMakeFiles/NeuralNetwork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NeuralNetwork.dir/depend

