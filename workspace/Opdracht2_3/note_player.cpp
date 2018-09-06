#include "note_player.hpp"

note_player_pc::note_player_pc()
{
}


void note_player_pc::play_tune(const char* s)
{
	
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i] != ',' && s[i] != ':')
			hwlib::cout<<s[i];
		else
			hwlib::cout<<"\n";
		i++;
	}
	hwlib::cout<<"\n";

}

note_player_pc::~note_player_pc()
{
}

