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
SOURCES := note_player_gpio.cpp rtttl_player.cpp note_player.cpp melody.cpp

# header files in this project
HEADERS := note.hpp note_player_gpio.hpp rtttl_player.hpp note_player.hpp melody.hpp

# other places to look for files for this project
SEARCH  := ../w1-library

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
