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
CMAKE_SOURCE_DIR = /home/sysprog/Desktop/Software/assignment5/monty_hall

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sysprog/Desktop/Software/assignment5/monty_hall/build

# Include any dependencies generated for this target.
include CMakeFiles/monty_hall_game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/monty_hall_game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/monty_hall_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/monty_hall_game.dir/flags.make

CMakeFiles/monty_hall_game.dir/main.cpp.o: CMakeFiles/monty_hall_game.dir/flags.make
CMakeFiles/monty_hall_game.dir/main.cpp.o: ../main.cpp
CMakeFiles/monty_hall_game.dir/main.cpp.o: CMakeFiles/monty_hall_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sysprog/Desktop/Software/assignment5/monty_hall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/monty_hall_game.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/monty_hall_game.dir/main.cpp.o -MF CMakeFiles/monty_hall_game.dir/main.cpp.o.d -o CMakeFiles/monty_hall_game.dir/main.cpp.o -c /home/sysprog/Desktop/Software/assignment5/monty_hall/main.cpp

CMakeFiles/monty_hall_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monty_hall_game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sysprog/Desktop/Software/assignment5/monty_hall/main.cpp > CMakeFiles/monty_hall_game.dir/main.cpp.i

CMakeFiles/monty_hall_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monty_hall_game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sysprog/Desktop/Software/assignment5/monty_hall/main.cpp -o CMakeFiles/monty_hall_game.dir/main.cpp.s

CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o: CMakeFiles/monty_hall_game.dir/flags.make
CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o: ../src/MontyHallGame.cpp
CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o: CMakeFiles/monty_hall_game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sysprog/Desktop/Software/assignment5/monty_hall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o -MF CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o.d -o CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o -c /home/sysprog/Desktop/Software/assignment5/monty_hall/src/MontyHallGame.cpp

CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sysprog/Desktop/Software/assignment5/monty_hall/src/MontyHallGame.cpp > CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.i

CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sysprog/Desktop/Software/assignment5/monty_hall/src/MontyHallGame.cpp -o CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.s

# Object files for target monty_hall_game
monty_hall_game_OBJECTS = \
"CMakeFiles/monty_hall_game.dir/main.cpp.o" \
"CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o"

# External object files for target monty_hall_game
monty_hall_game_EXTERNAL_OBJECTS =

monty_hall_game: CMakeFiles/monty_hall_game.dir/main.cpp.o
monty_hall_game: CMakeFiles/monty_hall_game.dir/src/MontyHallGame.cpp.o
monty_hall_game: CMakeFiles/monty_hall_game.dir/build.make
monty_hall_game: CMakeFiles/monty_hall_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sysprog/Desktop/Software/assignment5/monty_hall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable monty_hall_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/monty_hall_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/monty_hall_game.dir/build: monty_hall_game
.PHONY : CMakeFiles/monty_hall_game.dir/build

CMakeFiles/monty_hall_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/monty_hall_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/monty_hall_game.dir/clean

CMakeFiles/monty_hall_game.dir/depend:
	cd /home/sysprog/Desktop/Software/assignment5/monty_hall/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sysprog/Desktop/Software/assignment5/monty_hall /home/sysprog/Desktop/Software/assignment5/monty_hall /home/sysprog/Desktop/Software/assignment5/monty_hall/build /home/sysprog/Desktop/Software/assignment5/monty_hall/build /home/sysprog/Desktop/Software/assignment5/monty_hall/build/CMakeFiles/monty_hall_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/monty_hall_game.dir/depend

