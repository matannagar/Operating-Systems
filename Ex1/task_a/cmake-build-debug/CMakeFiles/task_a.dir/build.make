# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/matanbn/Downloads/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/matanbn/Downloads/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matanbn/CLionProjects/task_a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matanbn/CLionProjects/task_a/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task_a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task_a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task_a.dir/flags.make

CMakeFiles/task_a.dir/main1_1.c.o: CMakeFiles/task_a.dir/flags.make
CMakeFiles/task_a.dir/main1_1.c.o: ../main1_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matanbn/CLionProjects/task_a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task_a.dir/main1_1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task_a.dir/main1_1.c.o   -c /home/matanbn/CLionProjects/task_a/main1_1.c

CMakeFiles/task_a.dir/main1_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task_a.dir/main1_1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matanbn/CLionProjects/task_a/main1_1.c > CMakeFiles/task_a.dir/main1_1.c.i

CMakeFiles/task_a.dir/main1_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task_a.dir/main1_1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matanbn/CLionProjects/task_a/main1_1.c -o CMakeFiles/task_a.dir/main1_1.c.s

CMakeFiles/task_a.dir/hello_ariel.c.o: CMakeFiles/task_a.dir/flags.make
CMakeFiles/task_a.dir/hello_ariel.c.o: ../hello_ariel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matanbn/CLionProjects/task_a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/task_a.dir/hello_ariel.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task_a.dir/hello_ariel.c.o   -c /home/matanbn/CLionProjects/task_a/hello_ariel.c

CMakeFiles/task_a.dir/hello_ariel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task_a.dir/hello_ariel.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matanbn/CLionProjects/task_a/hello_ariel.c > CMakeFiles/task_a.dir/hello_ariel.c.i

CMakeFiles/task_a.dir/hello_ariel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task_a.dir/hello_ariel.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matanbn/CLionProjects/task_a/hello_ariel.c -o CMakeFiles/task_a.dir/hello_ariel.c.s

# Object files for target task_a
task_a_OBJECTS = \
"CMakeFiles/task_a.dir/main1_1.c.o" \
"CMakeFiles/task_a.dir/hello_ariel.c.o"

# External object files for target task_a
task_a_EXTERNAL_OBJECTS =

task_a: CMakeFiles/task_a.dir/main1_1.c.o
task_a: CMakeFiles/task_a.dir/hello_ariel.c.o
task_a: CMakeFiles/task_a.dir/build.make
task_a: CMakeFiles/task_a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matanbn/CLionProjects/task_a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable task_a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task_a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task_a.dir/build: task_a

.PHONY : CMakeFiles/task_a.dir/build

CMakeFiles/task_a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task_a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task_a.dir/clean

CMakeFiles/task_a.dir/depend:
	cd /home/matanbn/CLionProjects/task_a/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matanbn/CLionProjects/task_a /home/matanbn/CLionProjects/task_a /home/matanbn/CLionProjects/task_a/cmake-build-debug /home/matanbn/CLionProjects/task_a/cmake-build-debug /home/matanbn/CLionProjects/task_a/cmake-build-debug/CMakeFiles/task_a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task_a.dir/depend
