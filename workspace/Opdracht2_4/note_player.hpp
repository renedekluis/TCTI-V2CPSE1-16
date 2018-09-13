#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <istream>
#include <iterator>
#include <numeric>
#include <algorithm>




class note_player_pc
{
public:
	note_player_pc();
	
	void play_tune(const char* s);
	void write_cpp(const char* s);
	
	~note_player_pc();

};

