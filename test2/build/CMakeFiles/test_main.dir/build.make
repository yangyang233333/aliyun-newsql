# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/qianyy/work/woaikv/test2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qianyy/work/woaikv/test2/build

# Include any dependencies generated for this target.
include CMakeFiles/test_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_main.dir/flags.make

CMakeFiles/test_main.dir/test_main.cpp.o: CMakeFiles/test_main.dir/flags.make
CMakeFiles/test_main.dir/test_main.cpp.o: ../test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qianyy/work/woaikv/test2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_main.dir/test_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_main.dir/test_main.cpp.o -c /home/qianyy/work/woaikv/test2/test_main.cpp

CMakeFiles/test_main.dir/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_main.dir/test_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qianyy/work/woaikv/test2/test_main.cpp > CMakeFiles/test_main.dir/test_main.cpp.i

CMakeFiles/test_main.dir/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_main.dir/test_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qianyy/work/woaikv/test2/test_main.cpp -o CMakeFiles/test_main.dir/test_main.cpp.s

# Object files for target test_main
test_main_OBJECTS = \
"CMakeFiles/test_main.dir/test_main.cpp.o"

# External object files for target test_main
test_main_EXTERNAL_OBJECTS =

test_main: CMakeFiles/test_main.dir/test_main.cpp.o
test_main: CMakeFiles/test_main.dir/build.make
test_main: libinterface.so
test_main: /usr/lib/x86_64-linux-gnu/libpmem.so
test_main: CMakeFiles/test_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qianyy/work/woaikv/test2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_main.dir/build: test_main

.PHONY : CMakeFiles/test_main.dir/build

CMakeFiles/test_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_main.dir/clean

CMakeFiles/test_main.dir/depend:
	cd /home/qianyy/work/woaikv/test2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianyy/work/woaikv/test2 /home/qianyy/work/woaikv/test2 /home/qianyy/work/woaikv/test2/build /home/qianyy/work/woaikv/test2/build /home/qianyy/work/woaikv/test2/build/CMakeFiles/test_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_main.dir/depend

