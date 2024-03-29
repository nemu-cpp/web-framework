# This file was automatically generated by bakefile.
#
# Any manual changes will be lost if it is regenerated,
# modify the source .bkl file instead if possible.

# You may define standard make variables such as CFLAGS or
# CXXFLAGS to affect the build. For example, you could use:
#
#      make CXXFLAGS=-g
#
# to build with debug information. The full list of variables
# that can be used by this makefile is:
# AR, CC, CFLAGS, CPPFLAGS, CXX, CXXFLAGS, LD, LDFLAGS, MAKE, RANLIB.

# You may also specify config=Debug|Release
# or their corresponding lower case variants on make command line to select
# the corresponding default flags values.
ifeq ($(config),debug)
override config := Debug
endif
ifeq ($(config),release)
override config := Release
endif
ifeq ($(config),Debug)
override CPPFLAGS += -DDEBUG
override CFLAGS += -g -O0
override CXXFLAGS += -g -O0
override LDFLAGS += -g
else ifeq ($(config),Release)
override CPPFLAGS += -DNDEBUG
override CFLAGS += -O2
override CXXFLAGS += -O2
else ifneq (,$(config))
$(warning Unknown configuration "$(config)")
endif
#
# Additionally, this makefile is customizable with the following
# settings:
#
#      ISHIKO_CPP_BASEPLATFORM_ROOT   Path to the Ishiko BasePlatform installation
#      ISHIKO_CPP_ERRORS_ROOT         Path to the Ishiko Errors installation
#      ISHIKO_CPP_MEMORY_ROOT         Path to the Ishiko/C++ Memory installation
#      ISHIKO_CPP_BOOST_ROOT          Path to the Boost installation
#      ISHIKO_CPP_TEXT_ROOT           Path to the Ishiko/Text installation
#      ISHIKO_CPP_CONFIGURATION_ROOT  Path to the Ishiko Configuration installation
#      ISHIKO_CPP_BOTAN_ROOT          Path to the Botan installation
#      ISHIKO_CPP_NETWORKING_ROOT     Path to the Ishiko Networking installation
#      ISHIKO_CPP_FMT_ROOT            Path to the fmt installation
#      ISHIKO_CPP_TIME_ROOT           Path to the Ishiko Timeinstallation
#      ISHIKO_CPP_TYPES_ROOT          Path to the Ishiko Types installation
#      ISHIKO_CPP_HTTP_ROOT           Path to the Ishiko HTTP installation
#      ISHIKO_CPP_IO_ROOT             Path to the Ishiko/C++ IO installation
#      ISHIKO_CPP_FILESYSTEM_ROOT     Path to the Ishiko FileSystem installation
#      ISHIKO_CPP_LOGGING_ROOT        Path to the Ishiko Logging installation
#      NEMU_CPP_CORE_ROOT             Path to the Nemu installation
#      NEMU_CPP_WEBFRAMEWORK_ROOT     Path to the Nemu WebFramework installation

# Use "make RANLIB=''" for platforms without ranlib.
RANLIB ?= ranlib

CC := cc
CXX := c++

# The directory for the build files, may be overridden on make command line.
builddir = .

ifneq ($(builddir),.)
_builddir := $(if $(findstring $(abspath $(builddir)),$(builddir)),,../../)$(builddir)/../gnumake/
_builddir_error := $(shell mkdir -p $(_builddir) 2>&1)
$(if $(_builddir_error),$(error Failed to create build directory: $(_builddir_error)))
endif

# ------------
# Configurable settings:
# 

# Path to the Ishiko BasePlatform installation
ISHIKO_CPP_BASEPLATFORM_ROOT ?= $(ISHIKO_CPP)/base-platform
# Path to the Ishiko Errors installation
ISHIKO_CPP_ERRORS_ROOT ?= $(ISHIKO_CPP)/errors
# Path to the Ishiko/C++ Memory installation
ISHIKO_CPP_MEMORY_ROOT ?= $(ISHIKO_CPP)/memory
# Path to the Boost installation
ISHIKO_CPP_BOOST_ROOT ?= $(BOOST_ROOT)
# Path to the Ishiko/Text installation
ISHIKO_CPP_TEXT_ROOT ?= $(ISHIKO_CPP)/text
# Path to the Ishiko Configuration installation
ISHIKO_CPP_CONFIGURATION_ROOT ?= $(ISHIKO_CPP)/configuration
# Path to the Botan installation
ISHIKO_CPP_BOTAN_ROOT ?= $(BOTAN_ROOT)
# Path to the Ishiko Networking installation
ISHIKO_CPP_NETWORKING_ROOT ?= $(ISHIKO_CPP)/networking
# Path to the fmt installation
ISHIKO_CPP_FMT_ROOT ?= $(FMT_ROOT)
# Path to the Ishiko Timeinstallation
ISHIKO_CPP_TIME_ROOT ?= $(ISHIKO_CPP)/time
# Path to the Ishiko Types installation
ISHIKO_CPP_TYPES_ROOT ?= $(ISHIKO_CPP)/types
# Path to the Ishiko HTTP installation
ISHIKO_CPP_HTTP_ROOT ?= $(ISHIKO_CPP)/http
# Path to the Ishiko/C++ IO installation
ISHIKO_CPP_IO_ROOT ?= $(ISHIKO_CPP)/io
# Path to the Ishiko FileSystem installation
ISHIKO_CPP_FILESYSTEM_ROOT ?= $(ISHIKO_CPP)/filesystem
# Path to the Ishiko Logging installation
ISHIKO_CPP_LOGGING_ROOT ?= $(ISHIKO_CPP)/logging
# Path to the Nemu installation
NEMU_CPP_CORE_ROOT ?= $(NEMU_CPP)/core
# Path to the Nemu WebFramework installation
NEMU_CPP_WEBFRAMEWORK_ROOT ?= $(NEMU_CPP)/web-framework

# ------------

all: ../../bin/NemuStaticFilesServer

../../bin/NemuStaticFilesServer: $(_builddir)NemuStaticFilesServer_main.o
	@mkdir -p $(dir $@)
	$(CXX) -o $@ $(LDFLAGS) $(_builddir)NemuStaticFilesServer_main.o -L$(ISHIKO_CPP_MEMORY_ROOT)/lib -L$(ISHIKO_CPP_ERRORS_ROOT)/lib -L$(ISHIKO_CPP_BOOST_ROOT)/lib -L$(ISHIKO_CPP_TEXT_ROOT)/lib -L$(ISHIKO_CPP_BOTAN_ROOT)/lib -L$(ISHIKO_CPP_NETWORKING_ROOT)/lib -L$(ISHIKO_CPP_IO_ROOT)/lib -L$(ISHIKO_CPP_FILESYSTEM_ROOT)/lib -L$(ISHIKO_CPP_FMT_ROOT)/lib -L$(ISHIKO_CPP_TIME_ROOT)/lib -L$(ISHIKO_CPP_LOGGING_ROOT)/lib -L$(NEMU_CPP_CORE_ROOT)/lib -L$(ISHIKO_CPP_TYPES_ROOT)/lib -L$(ISHIKO_CPP_HTTP_ROOT)/lib -L$(ISHIKO_CPP_CONFIGURATION_ROOT)/lib -L$(NEMU_CPP_WEBFRAMEWORK_ROOT)/lib -lNemuWebFramework -lNemuCore -lIshikoHTTP -lIshikoNetworking -lIshikoFileSystem -lIshikoTime -lIshikoText -lIshikoTypes -lIshikoLogging -lIshikoMemory -lIshikoErrors -lfmt -lboost_filesystem -pthread

$(_builddir)NemuStaticFilesServer_main.o: ../../src/main.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_BOTAN_ROOT)/include/botan-2 -I$(ISHIKO_CPP_NETWORKING_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_LOGGING_ROOT)/include -I$(NEMU_CPP_CORE_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_HTTP_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(NEMU_CPP_WEBFRAMEWORK_ROOT)/include -std=c++11 ../../src/main.cpp

clean:
	rm -f $(_builddir)*.o
	rm -f $(_builddir)*.d
	rm -f ../../bin/NemuStaticFilesServer

.PHONY: all clean

# Dependencies tracking:
-include $(_builddir)*.d
