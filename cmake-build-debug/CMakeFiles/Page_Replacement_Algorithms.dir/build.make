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
CMAKE_COMMAND = /home/thiagofsr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/thiagofsr/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4445.84/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/thiagofsr/CLionProjects/Page Replacement Algorithms"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Page_Replacement_Algorithms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Page_Replacement_Algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Page_Replacement_Algorithms.dir/flags.make

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o: CMakeFiles/Page_Replacement_Algorithms.dir/flags.make
CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o -c "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/main.cpp"

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/main.cpp" > CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.i

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/main.cpp" -o CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.s

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.requires

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.provides: CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Page_Replacement_Algorithms.dir/build.make CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.provides

CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.provides.build: CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o


CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o: CMakeFiles/Page_Replacement_Algorithms.dir/flags.make
CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o: ../PageReplacement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o -c "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/PageReplacement.cpp"

CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/PageReplacement.cpp" > CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.i

CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/PageReplacement.cpp" -o CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.s

CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.requires:

.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.requires

CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.provides: CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.requires
	$(MAKE) -f CMakeFiles/Page_Replacement_Algorithms.dir/build.make CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.provides.build
.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.provides

CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.provides.build: CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o


CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o: CMakeFiles/Page_Replacement_Algorithms.dir/flags.make
CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o: ../StackList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o -c "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/StackList.cpp"

CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/StackList.cpp" > CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.i

CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/StackList.cpp" -o CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.s

CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.requires:

.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.requires

CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.provides: CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.requires
	$(MAKE) -f CMakeFiles/Page_Replacement_Algorithms.dir/build.make CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.provides.build
.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.provides

CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.provides.build: CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o


# Object files for target Page_Replacement_Algorithms
Page_Replacement_Algorithms_OBJECTS = \
"CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o" \
"CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o" \
"CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o"

# External object files for target Page_Replacement_Algorithms
Page_Replacement_Algorithms_EXTERNAL_OBJECTS =

Page_Replacement_Algorithms: CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o
Page_Replacement_Algorithms: CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o
Page_Replacement_Algorithms: CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o
Page_Replacement_Algorithms: CMakeFiles/Page_Replacement_Algorithms.dir/build.make
Page_Replacement_Algorithms: CMakeFiles/Page_Replacement_Algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Page_Replacement_Algorithms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Page_Replacement_Algorithms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Page_Replacement_Algorithms.dir/build: Page_Replacement_Algorithms

.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/build

CMakeFiles/Page_Replacement_Algorithms.dir/requires: CMakeFiles/Page_Replacement_Algorithms.dir/main.cpp.o.requires
CMakeFiles/Page_Replacement_Algorithms.dir/requires: CMakeFiles/Page_Replacement_Algorithms.dir/PageReplacement.cpp.o.requires
CMakeFiles/Page_Replacement_Algorithms.dir/requires: CMakeFiles/Page_Replacement_Algorithms.dir/StackList.cpp.o.requires

.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/requires

CMakeFiles/Page_Replacement_Algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Page_Replacement_Algorithms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/clean

CMakeFiles/Page_Replacement_Algorithms.dir/depend:
	cd "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/thiagofsr/CLionProjects/Page Replacement Algorithms" "/home/thiagofsr/CLionProjects/Page Replacement Algorithms" "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug" "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug" "/home/thiagofsr/CLionProjects/Page Replacement Algorithms/cmake-build-debug/CMakeFiles/Page_Replacement_Algorithms.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Page_Replacement_Algorithms.dir/depend
