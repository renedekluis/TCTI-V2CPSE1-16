#include "note_player.hpp"
#include <fstream>
//#include <iostream>

note_player_pc::note_player_pc()
{
}


void note_player_pc::play_tune(const char* s)
{
	
	int i = 0;
	while(s[i]!='\0')
	{
		if(s[i] != ',' && s[i] != ':')
		{
			hwlib::cout<<s[i];
		}
		else
			hwlib::cout<<"\n";
		i++;
	}
	hwlib::cout<<"\n";
}




void note_player_pc::write_cpp(const char* s)
{
	std::ofstream myFile;
	myFile.open("melody.cpp");
	if(!myFile.is_open())
	{
		hwlib::cout<<"Could not open file.\n";
	}
	myFile 	<< "#include \"melody.hpp\" \n\n"
			<< "void melody::play(note_player & p )";
	
	int i=0;
	
	int part =0;
	while(s[i]!='\0')
	{
		
		if(part==0)
		{
			char* substr = (char*)"";
			while(s[i]!=':')
			{
				i++;
			}
		}
		
		i++;
	}
	
			
	
	
}



note_player_pc::~note_player_pc()
{
}

