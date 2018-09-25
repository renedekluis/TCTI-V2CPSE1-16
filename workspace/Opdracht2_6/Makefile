

build : melody.cpp 


melody.cpp: Makefile converter.exe
	converter.exe "Toxicity:d=4,o=5,b=125:g,8p,16g,16g,8d#.,16c,g,8p,16g,16g,8d#.,16c,8g,2d#,8c,8g,2d,8p,g,8p,8g,8g,8g,8g,8g,8g,8g,8a#,8g,8d#,d#,8f,8d#,8d#,16d,16d#,16d,16c,2d,2d#.,2d#,16g#,16g#,16g#,8g#,g#,8a#,8g#,8g#,2d,8p,8c,8g,2d#,8c,8g,2d#,8c,g#,a#,8g#,8g"


converter.exe : converter.cpp
	g++ converter.cpp -o converter.exe

# source files in this project (main.cpp is automatically assumed)
SOURCES := note_player_gpio.cpp rtttl_player.cpp melody.cpp

# header files in this project
HEADERS := note.hpp note_player_gpio.hpp rtttl_player.hpp melody.hpp

# other places to look for files for this project
SEARCH  := ../w1-library
	

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
