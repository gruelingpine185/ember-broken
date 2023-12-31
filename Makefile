project_name := ember
project = $(bin_dir)/$(project_name)

# paths
inc_dir := inc/$(project_name)
src_dir := src
bin_dir := bin

# files
main := $(src_dir)/main.cpp
cpp_headers := $(wildcard $(inc_dir)/*.h)
cpp_sources := $(wildcard $(src_dir)/*.cpp)
cpp_objects := $(patsubst $(src_dir)/%.cpp, $(bin_dir)/%.o, \
	$(filter-out $(main), $(cpp_sources)))

lib_name := $(project_name)
lib_ext =
lib_full = $(bin_dir)/lib$(lib_name).$(lib_ext)

# compiler flags
cpp_std = -std=c++11
cpp_opt = -O2
cpp_wrn = -Wall -Wextra -pedantic
cpp_def =
cpp_inc = -I$(inc_dir)
CXX ?= clang
CXXFLAGS := $(strip $(cpp_std) $(cpp_opt) $(cpp_wrn) $(cpp_def) $(cpp_inc))


OS ?= $(shell uname -s)
ifeq ($(OS), Darwin)
	lib_ext = dylib
endif
ifeq ($(OS), Linux)
	lib_ext = so
endif
ifeq ($(OS), Windows_NT)
	lib_ext = dll
endif


.PHONY: all clean
all:
	@$(MAKE) $(project)
clean:
	-rm -rf $(bin_dir)

$(project): $(lib_full) $(main)
	$(CXX) $(CXXFLAGS) $(main) -o $@ -L$(bin_dir) -l$(lib_name)

$(bin_dir)/%.o: $(src_dir)/%.cpp $(wildcard $(inc_dir)/%.h) $(bin_dir)
	$(CXX) $(CXXFLAGS) -fpic -c $< -o $@

$(lib_full): $(cpp_objects) $(bin_dir)
	$(CXX) $(CXXFLAGS) -shared $(cpp_objects) -o $@

$(bin_dir):
	-mkdir $@
