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
include CMakeFiles/prims.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prims.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prims.dir/flags.make

CMakeFiles/prims.dir/prims.c.obj: CMakeFiles/prims.dir/flags.make
CMakeFiles/prims.dir/prims.c.obj: CMakeFiles/prims.dir/includes_C.rsp
CMakeFiles/prims.dir/prims.c.obj: prims.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prims.dir/prims.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\prims.dir\prims.c.obj   -c "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\prims.c"

CMakeFiles/prims.dir/prims.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prims.dir/prims.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\prims.c" > CMakeFiles\prims.dir\prims.c.i

CMakeFiles/prims.dir/prims.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prims.dir/prims.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\prims.c" -o CMakeFiles\prims.dir\prims.c.s

CMakeFiles/prims.dir/prims.c.obj.requires:

.PHONY : CMakeFiles/prims.dir/prims.c.obj.requires

CMakeFiles/prims.dir/prims.c.obj.provides: CMakeFiles/prims.dir/prims.c.obj.requires
	$(MAKE) -f CMakeFiles\prims.dir\build.make CMakeFiles/prims.dir/prims.c.obj.provides.build
.PHONY : CMakeFiles/prims.dir/prims.c.obj.provides

CMakeFiles/prims.dir/prims.c.obj.provides.build: CMakeFiles/prims.dir/prims.c.obj


# Object files for target prims
prims_OBJECTS = \
"CMakeFiles/prims.dir/prims.c.obj"

# External object files for target prims
prims_EXTERNAL_OBJECTS =

prims.exe: CMakeFiles/prims.dir/prims.c.obj
prims.exe: CMakeFiles/prims.dir/build.make
prims.exe: C:/Program\ Files\ (x86)/CodeBlocks/MinGW/lib/libfreeglut.a
prims.exe: CMakeFiles/prims.dir/linklibs.rsp
prims.exe: CMakeFiles/prims.dir/objects1.rsp
prims.exe: CMakeFiles/prims.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable prims.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\prims.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prims.dir/build: prims.exe

.PHONY : CMakeFiles/prims.dir/build

CMakeFiles/prims.dir/requires: CMakeFiles/prims.dir/prims.c.obj.requires

.PHONY : CMakeFiles/prims.dir/requires

CMakeFiles/prims.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\prims.dir\cmake_clean.cmake
.PHONY : CMakeFiles/prims.dir/clean

CMakeFiles/prims.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles\prims.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/prims.dir/depend
