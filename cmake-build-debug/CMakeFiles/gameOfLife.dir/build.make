# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gameOfLife.dir/flags.make

CMakeFiles/gameOfLife.dir/main.c.o: CMakeFiles/gameOfLife.dir/flags.make
CMakeFiles/gameOfLife.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gameOfLife.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gameOfLife.dir/main.c.o   -c /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/main.c

CMakeFiles/gameOfLife.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gameOfLife.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/main.c > CMakeFiles/gameOfLife.dir/main.c.i

CMakeFiles/gameOfLife.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gameOfLife.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/main.c -o CMakeFiles/gameOfLife.dir/main.c.s

CMakeFiles/gameOfLife.dir/main.c.o.requires:

.PHONY : CMakeFiles/gameOfLife.dir/main.c.o.requires

CMakeFiles/gameOfLife.dir/main.c.o.provides: CMakeFiles/gameOfLife.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/gameOfLife.dir/build.make CMakeFiles/gameOfLife.dir/main.c.o.provides.build
.PHONY : CMakeFiles/gameOfLife.dir/main.c.o.provides

CMakeFiles/gameOfLife.dir/main.c.o.provides.build: CMakeFiles/gameOfLife.dir/main.c.o


CMakeFiles/gameOfLife.dir/file_utilities.c.o: CMakeFiles/gameOfLife.dir/flags.make
CMakeFiles/gameOfLife.dir/file_utilities.c.o: ../file_utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gameOfLife.dir/file_utilities.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gameOfLife.dir/file_utilities.c.o   -c /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/file_utilities.c

CMakeFiles/gameOfLife.dir/file_utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gameOfLife.dir/file_utilities.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/file_utilities.c > CMakeFiles/gameOfLife.dir/file_utilities.c.i

CMakeFiles/gameOfLife.dir/file_utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gameOfLife.dir/file_utilities.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/file_utilities.c -o CMakeFiles/gameOfLife.dir/file_utilities.c.s

CMakeFiles/gameOfLife.dir/file_utilities.c.o.requires:

.PHONY : CMakeFiles/gameOfLife.dir/file_utilities.c.o.requires

CMakeFiles/gameOfLife.dir/file_utilities.c.o.provides: CMakeFiles/gameOfLife.dir/file_utilities.c.o.requires
	$(MAKE) -f CMakeFiles/gameOfLife.dir/build.make CMakeFiles/gameOfLife.dir/file_utilities.c.o.provides.build
.PHONY : CMakeFiles/gameOfLife.dir/file_utilities.c.o.provides

CMakeFiles/gameOfLife.dir/file_utilities.c.o.provides.build: CMakeFiles/gameOfLife.dir/file_utilities.c.o


# Object files for target gameOfLife
gameOfLife_OBJECTS = \
"CMakeFiles/gameOfLife.dir/main.c.o" \
"CMakeFiles/gameOfLife.dir/file_utilities.c.o"

# External object files for target gameOfLife
gameOfLife_EXTERNAL_OBJECTS =

gameOfLife: CMakeFiles/gameOfLife.dir/main.c.o
gameOfLife: CMakeFiles/gameOfLife.dir/file_utilities.c.o
gameOfLife: CMakeFiles/gameOfLife.dir/build.make
gameOfLife: CMakeFiles/gameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gameOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gameOfLife.dir/build: gameOfLife

.PHONY : CMakeFiles/gameOfLife.dir/build

CMakeFiles/gameOfLife.dir/requires: CMakeFiles/gameOfLife.dir/main.c.o.requires
CMakeFiles/gameOfLife.dir/requires: CMakeFiles/gameOfLife.dir/file_utilities.c.o.requires

.PHONY : CMakeFiles/gameOfLife.dir/requires

CMakeFiles/gameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gameOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gameOfLife.dir/clean

CMakeFiles/gameOfLife.dir/depend:
	cd /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug /Users/jacobwalton/Documents/Senior/cis343/gameOfLife/343-GameOfLife/cmake-build-debug/CMakeFiles/gameOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gameOfLife.dir/depend

