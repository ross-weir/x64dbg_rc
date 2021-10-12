# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.15)

# Regenerate CMakeLists.txt automatically in the root project
set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr
	include("cmake/cmkr.cmake" OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

# Create a configure-time dependency on cmake.toml to improve IDE support
if(CMKR_ROOT_PROJECT)
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

# Set up a more familiar Visual Studio configuration
# Override these options with -DCMAKE_OPTION=Value
#
# See: https://cmake.org/cmake/help/latest/command/set.html#set-cache-entry
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG:FULL /INCREMENTAL:NO" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/DEBUG:FULL /INCREMENTAL:NO" CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "")

project(PluginTemplate)

include("cmake/CPM.cmake")
include("cmake/x64dbg.cmake")

# Target PluginTemplate
set(CMKR_TARGET PluginTemplate)
set(PluginTemplate_SOURCES "")

list(APPEND PluginTemplate_SOURCES
	"src/plugin.cpp"
	"src/pluginmain.cpp"
	"src/plugin.h"
	"src/pluginmain.h"
)

list(APPEND PluginTemplate_SOURCES
	cmake.toml
)

set(CMKR_SOURCES ${PluginTemplate_SOURCES})
add_library(PluginTemplate SHARED)

if(PluginTemplate_SOURCES)
	target_sources(PluginTemplate PRIVATE ${PluginTemplate_SOURCES})
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PluginTemplate_SOURCES})

x64dbg_plugin(${CMKR_TARGET})

unset(CMKR_TARGET)
unset(CMKR_SOURCES)