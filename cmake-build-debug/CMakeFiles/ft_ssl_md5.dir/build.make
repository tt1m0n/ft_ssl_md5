# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /Users/omakovsk/Documents/ft_ssl_new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ft_ssl_md5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_ssl_md5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_ssl_md5.dir/flags.make

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o: ../src/ft_sha.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha.c

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha.c > CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o: ../src/ft_md5.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_md5.c

CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_md5.c > CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_md5.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o


CMakeFiles/ft_ssl_md5.dir/src/main.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ft_ssl_md5.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/main.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/main.c

CMakeFiles/ft_ssl_md5.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/main.c > CMakeFiles/ft_ssl_md5.dir/src/main.c.i

CMakeFiles/ft_ssl_md5.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/main.c -o CMakeFiles/ft_ssl_md5.dir/src/main.c.s

CMakeFiles/ft_ssl_md5.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/main.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/main.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/main.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/main.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/main.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o: ../src/ft_global.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_global.c

CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_global.c > CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_global.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o: ../src/ft_sha_384_512.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_384_512.c

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_384_512.c > CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_384_512.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o


CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o: ../src/init_start_words.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/init_start_words.c

CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/init_start_words.c > CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.i

CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/init_start_words.c -o CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.s

CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o: ../src/ft_main_hash_function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_main_hash_function.c

CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_main_hash_function.c > CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_main_hash_function.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o: ../src/ft_parse_and_read.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_parse_and_read.c

CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_parse_and_read.c > CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_parse_and_read.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o


CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o: CMakeFiles/ft_ssl_md5.dir/flags.make
CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o: ../src/ft_sha_helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o   -c /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_helpers.c

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_helpers.c > CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.i

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/omakovsk/Documents/ft_ssl_new/src/ft_sha_helpers.c -o CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.s

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.requires:

.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.requires

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.provides: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ssl_md5.dir/build.make CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.provides.build
.PHONY : CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.provides

CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.provides.build: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o


# Object files for target ft_ssl_md5
ft_ssl_md5_OBJECTS = \
"CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/main.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o" \
"CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o"

# External object files for target ft_ssl_md5
ft_ssl_md5_EXTERNAL_OBJECTS =

ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/main.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/build.make
ft_ssl_md5: ../libft/libft.a
ft_ssl_md5: CMakeFiles/ft_ssl_md5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable ft_ssl_md5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_ssl_md5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_ssl_md5.dir/build: ft_ssl_md5

.PHONY : CMakeFiles/ft_ssl_md5.dir/build

CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_sha.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_md5.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/main.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_global.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_384_512.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/init_start_words.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_main_hash_function.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_parse_and_read.c.o.requires
CMakeFiles/ft_ssl_md5.dir/requires: CMakeFiles/ft_ssl_md5.dir/src/ft_sha_helpers.c.o.requires

.PHONY : CMakeFiles/ft_ssl_md5.dir/requires

CMakeFiles/ft_ssl_md5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_ssl_md5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_ssl_md5.dir/clean

CMakeFiles/ft_ssl_md5.dir/depend:
	cd /Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omakovsk/Documents/ft_ssl_new /Users/omakovsk/Documents/ft_ssl_new /Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug /Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug /Users/omakovsk/Documents/ft_ssl_new/cmake-build-debug/CMakeFiles/ft_ssl_md5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_ssl_md5.dir/depend

