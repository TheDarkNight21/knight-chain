# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/farisallaf/CLionProjects/knight-chain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/firstBlockchain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/firstBlockchain.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/firstBlockchain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firstBlockchain.dir/flags.make

CMakeFiles/firstBlockchain.dir/main.cpp.o: CMakeFiles/firstBlockchain.dir/flags.make
CMakeFiles/firstBlockchain.dir/main.cpp.o: /Users/farisallaf/CLionProjects/knight-chain/main.cpp
CMakeFiles/firstBlockchain.dir/main.cpp.o: CMakeFiles/firstBlockchain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/firstBlockchain.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/firstBlockchain.dir/main.cpp.o -MF CMakeFiles/firstBlockchain.dir/main.cpp.o.d -o CMakeFiles/firstBlockchain.dir/main.cpp.o -c /Users/farisallaf/CLionProjects/knight-chain/main.cpp

CMakeFiles/firstBlockchain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/firstBlockchain.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/farisallaf/CLionProjects/knight-chain/main.cpp > CMakeFiles/firstBlockchain.dir/main.cpp.i

CMakeFiles/firstBlockchain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/firstBlockchain.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/farisallaf/CLionProjects/knight-chain/main.cpp -o CMakeFiles/firstBlockchain.dir/main.cpp.s

CMakeFiles/firstBlockchain.dir/sha256.cpp.o: CMakeFiles/firstBlockchain.dir/flags.make
CMakeFiles/firstBlockchain.dir/sha256.cpp.o: /Users/farisallaf/CLionProjects/knight-chain/sha256.cpp
CMakeFiles/firstBlockchain.dir/sha256.cpp.o: CMakeFiles/firstBlockchain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/firstBlockchain.dir/sha256.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/firstBlockchain.dir/sha256.cpp.o -MF CMakeFiles/firstBlockchain.dir/sha256.cpp.o.d -o CMakeFiles/firstBlockchain.dir/sha256.cpp.o -c /Users/farisallaf/CLionProjects/knight-chain/sha256.cpp

CMakeFiles/firstBlockchain.dir/sha256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/firstBlockchain.dir/sha256.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/farisallaf/CLionProjects/knight-chain/sha256.cpp > CMakeFiles/firstBlockchain.dir/sha256.cpp.i

CMakeFiles/firstBlockchain.dir/sha256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/firstBlockchain.dir/sha256.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/farisallaf/CLionProjects/knight-chain/sha256.cpp -o CMakeFiles/firstBlockchain.dir/sha256.cpp.s

CMakeFiles/firstBlockchain.dir/Block.cpp.o: CMakeFiles/firstBlockchain.dir/flags.make
CMakeFiles/firstBlockchain.dir/Block.cpp.o: /Users/farisallaf/CLionProjects/knight-chain/Block.cpp
CMakeFiles/firstBlockchain.dir/Block.cpp.o: CMakeFiles/firstBlockchain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/firstBlockchain.dir/Block.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/firstBlockchain.dir/Block.cpp.o -MF CMakeFiles/firstBlockchain.dir/Block.cpp.o.d -o CMakeFiles/firstBlockchain.dir/Block.cpp.o -c /Users/farisallaf/CLionProjects/knight-chain/Block.cpp

CMakeFiles/firstBlockchain.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/firstBlockchain.dir/Block.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/farisallaf/CLionProjects/knight-chain/Block.cpp > CMakeFiles/firstBlockchain.dir/Block.cpp.i

CMakeFiles/firstBlockchain.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/firstBlockchain.dir/Block.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/farisallaf/CLionProjects/knight-chain/Block.cpp -o CMakeFiles/firstBlockchain.dir/Block.cpp.s

CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o: CMakeFiles/firstBlockchain.dir/flags.make
CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o: /Users/farisallaf/CLionProjects/knight-chain/Blockchain.cpp
CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o: CMakeFiles/firstBlockchain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o -MF CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o.d -o CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o -c /Users/farisallaf/CLionProjects/knight-chain/Blockchain.cpp

CMakeFiles/firstBlockchain.dir/Blockchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/firstBlockchain.dir/Blockchain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/farisallaf/CLionProjects/knight-chain/Blockchain.cpp > CMakeFiles/firstBlockchain.dir/Blockchain.cpp.i

CMakeFiles/firstBlockchain.dir/Blockchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/firstBlockchain.dir/Blockchain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/farisallaf/CLionProjects/knight-chain/Blockchain.cpp -o CMakeFiles/firstBlockchain.dir/Blockchain.cpp.s

# Object files for target firstBlockchain
firstBlockchain_OBJECTS = \
"CMakeFiles/firstBlockchain.dir/main.cpp.o" \
"CMakeFiles/firstBlockchain.dir/sha256.cpp.o" \
"CMakeFiles/firstBlockchain.dir/Block.cpp.o" \
"CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o"

# External object files for target firstBlockchain
firstBlockchain_EXTERNAL_OBJECTS =

firstBlockchain: CMakeFiles/firstBlockchain.dir/main.cpp.o
firstBlockchain: CMakeFiles/firstBlockchain.dir/sha256.cpp.o
firstBlockchain: CMakeFiles/firstBlockchain.dir/Block.cpp.o
firstBlockchain: CMakeFiles/firstBlockchain.dir/Blockchain.cpp.o
firstBlockchain: CMakeFiles/firstBlockchain.dir/build.make
firstBlockchain: CMakeFiles/firstBlockchain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable firstBlockchain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firstBlockchain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firstBlockchain.dir/build: firstBlockchain
.PHONY : CMakeFiles/firstBlockchain.dir/build

CMakeFiles/firstBlockchain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firstBlockchain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firstBlockchain.dir/clean

CMakeFiles/firstBlockchain.dir/depend:
	cd /Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/farisallaf/CLionProjects/knight-chain /Users/farisallaf/CLionProjects/knight-chain /Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug /Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug /Users/farisallaf/CLionProjects/knight-chain/cmake-build-debug/CMakeFiles/firstBlockchain.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/firstBlockchain.dir/depend
