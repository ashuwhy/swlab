# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sysprog/Desktop/Software/assignment5/my_string

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sysprog/Desktop/Software/assignment5/my_string/build

# Utility rule file for coverage_clean.

# Include any custom commands dependencies for this target.
include CMakeFiles/coverage_clean.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/coverage_clean.dir/progress.make

CMakeFiles/coverage_clean:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sysprog/Desktop/Software/assignment5/my_string/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Deleted the coverage files"
	find . -name *.gcda -delete
	find . -name *.gcno -delete

coverage_clean: CMakeFiles/coverage_clean
coverage_clean: CMakeFiles/coverage_clean.dir/build.make
.PHONY : coverage_clean

# Rule to build all files generated by this target.
CMakeFiles/coverage_clean.dir/build: coverage_clean
.PHONY : CMakeFiles/coverage_clean.dir/build

CMakeFiles/coverage_clean.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coverage_clean.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coverage_clean.dir/clean

CMakeFiles/coverage_clean.dir/depend:
	cd /home/sysprog/Desktop/Software/assignment5/my_string/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sysprog/Desktop/Software/assignment5/my_string /home/sysprog/Desktop/Software/assignment5/my_string /home/sysprog/Desktop/Software/assignment5/my_string/build /home/sysprog/Desktop/Software/assignment5/my_string/build /home/sysprog/Desktop/Software/assignment5/my_string/build/CMakeFiles/coverage_clean.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coverage_clean.dir/depend

