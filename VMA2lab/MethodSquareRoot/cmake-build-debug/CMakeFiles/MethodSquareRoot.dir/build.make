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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\teren\Documents\VMA2lab\MethodSquareRoot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\MethodSquareRoot.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\MethodSquareRoot.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\MethodSquareRoot.dir\flags.make

CMakeFiles\MethodSquareRoot.dir\main.cpp.obj: CMakeFiles\MethodSquareRoot.dir\flags.make
CMakeFiles\MethodSquareRoot.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MethodSquareRoot.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\PROFES~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\MethodSquareRoot.dir\main.cpp.obj /FdCMakeFiles\MethodSquareRoot.dir\ /FS -c C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\main.cpp
<<

CMakeFiles\MethodSquareRoot.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MethodSquareRoot.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\PROFES~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\MethodSquareRoot.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\main.cpp
<<

CMakeFiles\MethodSquareRoot.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MethodSquareRoot.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\PROFES~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\MethodSquareRoot.dir\main.cpp.s /c C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\main.cpp
<<

# Object files for target MethodSquareRoot
MethodSquareRoot_OBJECTS = \
"CMakeFiles\MethodSquareRoot.dir\main.cpp.obj"

# External object files for target MethodSquareRoot
MethodSquareRoot_EXTERNAL_OBJECTS =

MethodSquareRoot.exe: CMakeFiles\MethodSquareRoot.dir\main.cpp.obj
MethodSquareRoot.exe: CMakeFiles\MethodSquareRoot.dir\build.make
MethodSquareRoot.exe: CMakeFiles\MethodSquareRoot.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MethodSquareRoot.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\MethodSquareRoot.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\PROFES~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\MethodSquareRoot.dir\objects1.rsp @<<
 /out:MethodSquareRoot.exe /implib:MethodSquareRoot.lib /pdb:C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug\MethodSquareRoot.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\MethodSquareRoot.dir\build: MethodSquareRoot.exe

.PHONY : CMakeFiles\MethodSquareRoot.dir\build

CMakeFiles\MethodSquareRoot.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MethodSquareRoot.dir\cmake_clean.cmake
.PHONY : CMakeFiles\MethodSquareRoot.dir\clean

CMakeFiles\MethodSquareRoot.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\teren\Documents\VMA2lab\MethodSquareRoot C:\Users\teren\Documents\VMA2lab\MethodSquareRoot C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug C:\Users\teren\Documents\VMA2lab\MethodSquareRoot\cmake-build-debug\CMakeFiles\MethodSquareRoot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\MethodSquareRoot.dir\depend

