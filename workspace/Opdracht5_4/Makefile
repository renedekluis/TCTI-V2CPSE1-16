#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := compressed.asm decompressor.asm

# header files in this project
HEADERS := compressor.hpp

# other places to look for files for this project
SEARCH  := ../w1-library


# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due


.PHONY: build main.exe

build: compressed.asm

compressed.asm: textfile.txt compressor.exe
	compressor.exe
	

compressor.exe: compressor.hpp compressor.cpp
	g++ compressor.cpp -o compressor.exe