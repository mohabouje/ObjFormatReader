# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /Developer/C++/ObjFormatReader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Developer/C++/ObjFormatReader

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Developer/C++/ObjFormatReader/CMakeFiles /Developer/C++/ObjFormatReader/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Developer/C++/ObjFormatReader/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named runbenchmark

# Build rule for target.
runbenchmark: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runbenchmark
.PHONY : runbenchmark

# fast build rule for target.
runbenchmark/fast:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/build
.PHONY : runbenchmark/fast

#=============================================================================
# Target rules for targets named runtest

# Build rule for target.
runtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runtest
.PHONY : runtest

# fast build rule for target.
runtest/fast:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/build
.PHONY : runtest/fast

#=============================================================================
# Target rules for targets named ObjFormatReader

# Build rule for target.
ObjFormatReader: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ObjFormatReader
.PHONY : ObjFormatReader

# fast build rule for target.
ObjFormatReader/fast:
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/build
.PHONY : ObjFormatReader/fast

benchmarks/impl_benchmarks.o: benchmarks/impl_benchmarks.cpp.o

.PHONY : benchmarks/impl_benchmarks.o

# target to build an object file
benchmarks/impl_benchmarks.cpp.o:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/impl_benchmarks.cpp.o
.PHONY : benchmarks/impl_benchmarks.cpp.o

benchmarks/impl_benchmarks.i: benchmarks/impl_benchmarks.cpp.i

.PHONY : benchmarks/impl_benchmarks.i

# target to preprocess a source file
benchmarks/impl_benchmarks.cpp.i:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/impl_benchmarks.cpp.i
.PHONY : benchmarks/impl_benchmarks.cpp.i

benchmarks/impl_benchmarks.s: benchmarks/impl_benchmarks.cpp.s

.PHONY : benchmarks/impl_benchmarks.s

# target to generate assembly for a file
benchmarks/impl_benchmarks.cpp.s:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/impl_benchmarks.cpp.s
.PHONY : benchmarks/impl_benchmarks.cpp.s

benchmarks/objformat_benchmark.o: benchmarks/objformat_benchmark.cpp.o

.PHONY : benchmarks/objformat_benchmark.o

# target to build an object file
benchmarks/objformat_benchmark.cpp.o:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/objformat_benchmark.cpp.o
.PHONY : benchmarks/objformat_benchmark.cpp.o

benchmarks/objformat_benchmark.i: benchmarks/objformat_benchmark.cpp.i

.PHONY : benchmarks/objformat_benchmark.i

# target to preprocess a source file
benchmarks/objformat_benchmark.cpp.i:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/objformat_benchmark.cpp.i
.PHONY : benchmarks/objformat_benchmark.cpp.i

benchmarks/objformat_benchmark.s: benchmarks/objformat_benchmark.cpp.s

.PHONY : benchmarks/objformat_benchmark.s

# target to generate assembly for a file
benchmarks/objformat_benchmark.cpp.s:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/benchmarks/objformat_benchmark.cpp.s
.PHONY : benchmarks/objformat_benchmark.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/main.cpp.s
.PHONY : main.cpp.s

objformat_reader.o: objformat_reader.cpp.o

.PHONY : objformat_reader.o

# target to build an object file
objformat_reader.cpp.o:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/objformat_reader.cpp.o
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/objformat_reader.cpp.o
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/objformat_reader.cpp.o
.PHONY : objformat_reader.cpp.o

objformat_reader.i: objformat_reader.cpp.i

.PHONY : objformat_reader.i

# target to preprocess a source file
objformat_reader.cpp.i:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/objformat_reader.cpp.i
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/objformat_reader.cpp.i
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/objformat_reader.cpp.i
.PHONY : objformat_reader.cpp.i

objformat_reader.s: objformat_reader.cpp.s

.PHONY : objformat_reader.s

# target to generate assembly for a file
objformat_reader.cpp.s:
	$(MAKE) -f CMakeFiles/runbenchmark.dir/build.make CMakeFiles/runbenchmark.dir/objformat_reader.cpp.s
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/objformat_reader.cpp.s
	$(MAKE) -f CMakeFiles/ObjFormatReader.dir/build.make CMakeFiles/ObjFormatReader.dir/objformat_reader.cpp.s
.PHONY : objformat_reader.cpp.s

test/objformat_test.o: test/objformat_test.cpp.o

.PHONY : test/objformat_test.o

# target to build an object file
test/objformat_test.cpp.o:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/objformat_test.cpp.o
.PHONY : test/objformat_test.cpp.o

test/objformat_test.i: test/objformat_test.cpp.i

.PHONY : test/objformat_test.i

# target to preprocess a source file
test/objformat_test.cpp.i:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/objformat_test.cpp.i
.PHONY : test/objformat_test.cpp.i

test/objformat_test.s: test/objformat_test.cpp.s

.PHONY : test/objformat_test.s

# target to generate assembly for a file
test/objformat_test.cpp.s:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/objformat_test.cpp.s
.PHONY : test/objformat_test.cpp.s

test/utility_test.o: test/utility_test.cpp.o

.PHONY : test/utility_test.o

# target to build an object file
test/utility_test.cpp.o:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/utility_test.cpp.o
.PHONY : test/utility_test.cpp.o

test/utility_test.i: test/utility_test.cpp.i

.PHONY : test/utility_test.i

# target to preprocess a source file
test/utility_test.cpp.i:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/utility_test.cpp.i
.PHONY : test/utility_test.cpp.i

test/utility_test.s: test/utility_test.cpp.s

.PHONY : test/utility_test.s

# target to generate assembly for a file
test/utility_test.cpp.s:
	$(MAKE) -f CMakeFiles/runtest.dir/build.make CMakeFiles/runtest.dir/test/utility_test.cpp.s
.PHONY : test/utility_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... runbenchmark"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... runtest"
	@echo "... ObjFormatReader"
	@echo "... benchmarks/impl_benchmarks.o"
	@echo "... benchmarks/impl_benchmarks.i"
	@echo "... benchmarks/impl_benchmarks.s"
	@echo "... benchmarks/objformat_benchmark.o"
	@echo "... benchmarks/objformat_benchmark.i"
	@echo "... benchmarks/objformat_benchmark.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... objformat_reader.o"
	@echo "... objformat_reader.i"
	@echo "... objformat_reader.s"
	@echo "... test/objformat_test.o"
	@echo "... test/objformat_test.i"
	@echo "... test/objformat_test.s"
	@echo "... test/utility_test.o"
	@echo "... test/utility_test.i"
	@echo "... test/utility_test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

