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
SOURCES := pause_detector.cpp ir_receiver.cpp msg_decoder.cpp msg_logger.cpp

# header files in this project
HEADERS := pause_detector.hpp ir_receiver.hpp pause_listener.hpp msg_decoder.hpp msg_listener.hpp msg_logger.hpp

# other places to look for files for this project
SEARCH  := ../w1-library


# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due

