# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lowrider\CLionProjects\playground

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lowrider\CLionProjects\playground\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\playground.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\playground.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\playground.dir\flags.make

CMakeFiles\playground.dir\main.c.obj: CMakeFiles\playground.dir\flags.make
CMakeFiles\playground.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/playground.dir/main.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\playground.dir\main.c.obj /FdCMakeFiles\playground.dir\ /FS -c C:\Users\lowrider\CLionProjects\playground\main.c
<<

CMakeFiles\playground.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playground.dir/main.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\playground.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lowrider\CLionProjects\playground\main.c
<<

CMakeFiles\playground.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playground.dir/main.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\playground.dir\main.c.s /c C:\Users\lowrider\CLionProjects\playground\main.c
<<

CMakeFiles\playground.dir\parser.c.obj: CMakeFiles\playground.dir\flags.make
CMakeFiles\playground.dir\parser.c.obj: ..\parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/playground.dir/parser.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\playground.dir\parser.c.obj /FdCMakeFiles\playground.dir\ /FS -c C:\Users\lowrider\CLionProjects\playground\parser.c
<<

CMakeFiles\playground.dir\parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playground.dir/parser.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\playground.dir\parser.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lowrider\CLionProjects\playground\parser.c
<<

CMakeFiles\playground.dir\parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playground.dir/parser.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\playground.dir\parser.c.s /c C:\Users\lowrider\CLionProjects\playground\parser.c
<<

CMakeFiles\playground.dir\tiled.c.obj: CMakeFiles\playground.dir\flags.make
CMakeFiles\playground.dir\tiled.c.obj: ..\tiled.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/playground.dir/tiled.c.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\playground.dir\tiled.c.obj /FdCMakeFiles\playground.dir\ /FS -c C:\Users\lowrider\CLionProjects\playground\tiled.c
<<

CMakeFiles\playground.dir\tiled.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/playground.dir/tiled.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\playground.dir\tiled.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lowrider\CLionProjects\playground\tiled.c
<<

CMakeFiles\playground.dir\tiled.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/playground.dir/tiled.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\playground.dir\tiled.c.s /c C:\Users\lowrider\CLionProjects\playground\tiled.c
<<

# Object files for target playground
playground_OBJECTS = \
"CMakeFiles\playground.dir\main.c.obj" \
"CMakeFiles\playground.dir\parser.c.obj" \
"CMakeFiles\playground.dir\tiled.c.obj"

# External object files for target playground
playground_EXTERNAL_OBJECTS =

playground.exe: CMakeFiles\playground.dir\main.c.obj
playground.exe: CMakeFiles\playground.dir\parser.c.obj
playground.exe: CMakeFiles\playground.dir\tiled.c.obj
playground.exe: CMakeFiles\playground.dir\build.make
playground.exe: CMakeFiles\playground.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable playground.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\playground.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\playground.dir\objects1.rsp @<<
 /out:playground.exe /implib:playground.lib /pdb:C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\playground.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\playground.dir\build: playground.exe

.PHONY : CMakeFiles\playground.dir\build

CMakeFiles\playground.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\playground.dir\cmake_clean.cmake
.PHONY : CMakeFiles\playground.dir\clean

CMakeFiles\playground.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\lowrider\CLionProjects\playground C:\Users\lowrider\CLionProjects\playground C:\Users\lowrider\CLionProjects\playground\cmake-build-debug C:\Users\lowrider\CLionProjects\playground\cmake-build-debug C:\Users\lowrider\CLionProjects\playground\cmake-build-debug\CMakeFiles\playground.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\playground.dir\depend
