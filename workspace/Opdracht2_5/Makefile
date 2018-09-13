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
SOURCES := note_player_gpio.cpp rtttl_player.cpp melody.cpp converter.cpp
# header files in this project
HEADERS := note.hpp note_player_gpio.hpp rtttl_player.hpp melody.hpp

# other places to look for files for this project
SEARCH  := ../w1-library


#melody.cpp : converter.exe Makefile
#	converter.exe "Computer Games - Super Mario Brothers 1.txt"

converter.exe : converter.o
	gcc converter.o -o converter.exe
	
converter.o : converter.cpp
	gcc -c converter.cpp -o converter.o





# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
