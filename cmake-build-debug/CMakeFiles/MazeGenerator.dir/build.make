# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Naman Jain\CLionProjects\untitled"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MazeGenerator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MazeGenerator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MazeGenerator.dir/flags.make

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj: CMakeFiles/MazeGenerator.dir/flags.make
CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj: CMakeFiles/MazeGenerator.dir/includes_C.rsp
CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj: ../MazeGenerator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MazeGenerator.dir\MazeGenerator.c.obj   -c "C:\Users\Naman Jain\CLionProjects\untitled\MazeGenerator.c"

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MazeGenerator.dir/MazeGenerator.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Naman Jain\CLionProjects\untitled\MazeGenerator.c" > CMakeFiles\MazeGenerator.dir\MazeGenerator.c.i

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MazeGenerator.dir/MazeGenerator.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Naman Jain\CLionProjects\untitled\MazeGenerator.c" -o CMakeFiles\MazeGenerator.dir\MazeGenerator.c.s

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.requires:

.PHONY : CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.requires

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.provides: CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.requires
	$(MAKE) -f CMakeFiles\MazeGenerator.dir\build.make CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.provides.build
.PHONY : CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.provides

CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.provides.build: CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj


# Object files for target MazeGenerator
MazeGenerator_OBJECTS = \
"CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj"

# External object files for target MazeGenerator
MazeGenerator_EXTERNAL_OBJECTS =

MazeGenerator.exe: CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj
MazeGenerator.exe: CMakeFiles/MazeGenerator.dir/build.make
MazeGenerator.exe: C:/Program\ Files\ (x86)/CodeBlocks/MinGW/lib/libfreeglut.a
MazeGenerator.exe: CMakeFiles/MazeGenerator.dir/linklibs.rsp
MazeGenerator.exe: CMakeFiles/MazeGenerator.dir/objects1.rsp
MazeGenerator.exe: CMakeFiles/MazeGenerator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MazeGenerator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MazeGenerator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MazeGenerator.dir/build: MazeGenerator.exe

.PHONY : CMakeFiles/MazeGenerator.dir/build

CMakeFiles/MazeGenerator.dir/requires: CMakeFiles/MazeGenerator.dir/MazeGenerator.c.obj.requires

.PHONY : CMakeFiles/MazeGenerator.dir/requires

CMakeFiles/MazeGenerator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MazeGenerator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MazeGenerator.dir/clean

CMakeFiles/MazeGenerator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles\MazeGenerator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MazeGenerator.dir/depend
