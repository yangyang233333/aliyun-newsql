# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/qianyangyang/.cache/JetBrains/RemoteDev/dist/aba04351ed0da_CLion-2022.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/qianyangyang/.cache/JetBrains/RemoteDev/dist/aba04351ed0da_CLion-2022.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qianyangyang/ide/clion/woaikv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qianyangyang/ide/clion/woaikv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/interface.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/interface.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/interface.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interface.dir/flags.make

CMakeFiles/interface.dir/src/common.cpp.o: CMakeFiles/interface.dir/flags.make
CMakeFiles/interface.dir/src/common.cpp.o: ../src/common.cpp
CMakeFiles/interface.dir/src/common.cpp.o: CMakeFiles/interface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qianyangyang/ide/clion/woaikv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interface.dir/src/common.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/interface.dir/src/common.cpp.o -MF CMakeFiles/interface.dir/src/common.cpp.o.d -o CMakeFiles/interface.dir/src/common.cpp.o -c /home/qianyangyang/ide/clion/woaikv/src/common.cpp

CMakeFiles/interface.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interface.dir/src/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qianyangyang/ide/clion/woaikv/src/common.cpp > CMakeFiles/interface.dir/src/common.cpp.i

CMakeFiles/interface.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interface.dir/src/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qianyangyang/ide/clion/woaikv/src/common.cpp -o CMakeFiles/interface.dir/src/common.cpp.s

CMakeFiles/interface.dir/src/interface.cpp.o: CMakeFiles/interface.dir/flags.make
CMakeFiles/interface.dir/src/interface.cpp.o: ../src/interface.cpp
CMakeFiles/interface.dir/src/interface.cpp.o: CMakeFiles/interface.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qianyangyang/ide/clion/woaikv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/interface.dir/src/interface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/interface.dir/src/interface.cpp.o -MF CMakeFiles/interface.dir/src/interface.cpp.o.d -o CMakeFiles/interface.dir/src/interface.cpp.o -c /home/qianyangyang/ide/clion/woaikv/src/interface.cpp

CMakeFiles/interface.dir/src/interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interface.dir/src/interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qianyangyang/ide/clion/woaikv/src/interface.cpp > CMakeFiles/interface.dir/src/interface.cpp.i

CMakeFiles/interface.dir/src/interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interface.dir/src/interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qianyangyang/ide/clion/woaikv/src/interface.cpp -o CMakeFiles/interface.dir/src/interface.cpp.s

# Object files for target interface
interface_OBJECTS = \
"CMakeFiles/interface.dir/src/common.cpp.o" \
"CMakeFiles/interface.dir/src/interface.cpp.o"

# External object files for target interface
interface_EXTERNAL_OBJECTS =

libinterface.so: CMakeFiles/interface.dir/src/common.cpp.o
libinterface.so: CMakeFiles/interface.dir/src/interface.cpp.o
libinterface.so: CMakeFiles/interface.dir/build.make
libinterface.so: CMakeFiles/interface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qianyangyang/ide/clion/woaikv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libinterface.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interface.dir/build: libinterface.so
.PHONY : CMakeFiles/interface.dir/build

CMakeFiles/interface.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interface.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interface.dir/clean

CMakeFiles/interface.dir/depend:
	cd /home/qianyangyang/ide/clion/woaikv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qianyangyang/ide/clion/woaikv /home/qianyangyang/ide/clion/woaikv /home/qianyangyang/ide/clion/woaikv/cmake-build-debug /home/qianyangyang/ide/clion/woaikv/cmake-build-debug /home/qianyangyang/ide/clion/woaikv/cmake-build-debug/CMakeFiles/interface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interface.dir/depend

