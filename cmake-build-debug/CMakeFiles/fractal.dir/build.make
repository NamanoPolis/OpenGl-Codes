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
include CMakeFiles/fractal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fractal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fractal.dir/flags.make

CMakeFiles/fractal.dir/fractal.c.obj: CMakeFiles/fractal.dir/flags.make
CMakeFiles/fractal.dir/fractal.c.obj: CMakeFiles/fractal.dir/includes_C.rsp
CMakeFiles/fractal.dir/fractal.c.obj: ../fractal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fractal.dir/fractal.c.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\fractal.dir\fractal.c.obj   -c "C:\Users\Naman Jain\CLionProjects\untitled\fractal.c"

CMakeFiles/fractal.dir/fractal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fractal.dir/fractal.c.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Naman Jain\CLionProjects\untitled\fractal.c" > CMakeFiles\fractal.dir\fractal.c.i

CMakeFiles/fractal.dir/fractal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fractal.dir/fractal.c.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Naman Jain\CLionProjects\untitled\fractal.c" -o CMakeFiles\fractal.dir\fractal.c.s

CMakeFiles/fractal.dir/fractal.c.obj.requires:

.PHONY : CMakeFiles/fractal.dir/fractal.c.obj.requires

CMakeFiles/fractal.dir/fractal.c.obj.provides: CMakeFiles/fractal.dir/fractal.c.obj.requires
	$(MAKE) -f CMakeFiles\fractal.dir\build.make CMakeFiles/fractal.dir/fractal.c.obj.provides.build
.PHONY : CMakeFiles/fractal.dir/fractal.c.obj.provides

CMakeFiles/fractal.dir/fractal.c.obj.provides.build: CMakeFiles/fractal.dir/fractal.c.obj


# Object files for target fractal
fractal_OBJECTS = \
"CMakeFiles/fractal.dir/fractal.c.obj"

# External object files for target fractal
fractal_EXTERNAL_OBJECTS =

fractal.exe: CMakeFiles/fractal.dir/fractal.c.obj
fractal.exe: CMakeFiles/fractal.dir/build.make
fractal.exe: C:/Program\ Files\ (x86)/CodeBlocks/MinGW/lib/libfreeglut.a
fractal.exe: CMakeFiles/fractal.dir/linklibs.rsp
fractal.exe: CMakeFiles/fractal.dir/objects1.rsp
fractal.exe: CMakeFiles/fractal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fractal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fractal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fractal.dir/build: fractal.exe

.PHONY : CMakeFiles/fractal.dir/build

CMakeFiles/fractal.dir/requires: CMakeFiles/fractal.dir/fractal.c.obj.requires

.PHONY : CMakeFiles/fractal.dir/requires

CMakeFiles/fractal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fractal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fractal.dir/clean

CMakeFiles/fractal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug" "C:\Users\Naman Jain\CLionProjects\untitled\cmake-build-debug\CMakeFiles\fractal.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fractal.dir/depend
