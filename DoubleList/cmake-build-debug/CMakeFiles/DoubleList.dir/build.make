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
CMAKE_SOURCE_DIR = /home/alexander/Apps/clion-2018.1.5/DoubleList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DoubleList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DoubleList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoubleList.dir/flags.make

CMakeFiles/DoubleList.dir/main.cpp.o: CMakeFiles/DoubleList.dir/flags.make
CMakeFiles/DoubleList.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoubleList.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DoubleList.dir/main.cpp.o -c /home/alexander/Apps/clion-2018.1.5/DoubleList/main.cpp

CMakeFiles/DoubleList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoubleList.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/Apps/clion-2018.1.5/DoubleList/main.cpp > CMakeFiles/DoubleList.dir/main.cpp.i

CMakeFiles/DoubleList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoubleList.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/Apps/clion-2018.1.5/DoubleList/main.cpp -o CMakeFiles/DoubleList.dir/main.cpp.s

CMakeFiles/DoubleList.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DoubleList.dir/main.cpp.o.requires

CMakeFiles/DoubleList.dir/main.cpp.o.provides: CMakeFiles/DoubleList.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DoubleList.dir/build.make CMakeFiles/DoubleList.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DoubleList.dir/main.cpp.o.provides

CMakeFiles/DoubleList.dir/main.cpp.o.provides.build: CMakeFiles/DoubleList.dir/main.cpp.o


# Object files for target DoubleList
DoubleList_OBJECTS = \
"CMakeFiles/DoubleList.dir/main.cpp.o"

# External object files for target DoubleList
DoubleList_EXTERNAL_OBJECTS =

DoubleList: CMakeFiles/DoubleList.dir/main.cpp.o
DoubleList: CMakeFiles/DoubleList.dir/build.make
DoubleList: CMakeFiles/DoubleList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DoubleList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DoubleList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoubleList.dir/build: DoubleList

.PHONY : CMakeFiles/DoubleList.dir/build

CMakeFiles/DoubleList.dir/requires: CMakeFiles/DoubleList.dir/main.cpp.o.requires

.PHONY : CMakeFiles/DoubleList.dir/requires

CMakeFiles/DoubleList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DoubleList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DoubleList.dir/clean

CMakeFiles/DoubleList.dir/depend:
	cd /home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/Apps/clion-2018.1.5/DoubleList /home/alexander/Apps/clion-2018.1.5/DoubleList /home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug /home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug /home/alexander/Apps/clion-2018.1.5/DoubleList/cmake-build-debug/CMakeFiles/DoubleList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DoubleList.dir/depend

