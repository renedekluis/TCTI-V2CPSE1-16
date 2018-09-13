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
		{
			std::cout<<s[i];
		}
		else
			std::cout<<"\n";
		i++;
	}
	std::cout<<"\n";
}



void note_player_pc::write_cpp(const char* s)
{
	
	std::ofstream myFile;
	myFile.open("../../w1-library/melody.cpp");
	
	if(!myFile.is_open())
	{
		std::cout<<"Could not open file.\n";
	}
			
	myFile 	<< "#include \"melody.hpp\" \n\n"
			<< "void melody::play(note_player & p ){\n";
				
	
	int strIdx=0;
	
	int part =0;

	
	
	
	
	std::string title = "";
	while(s[strIdx]!=':' && s[strIdx] != '\0' )
	{
		title += s[strIdx];
		strIdx++;
	}
	//std::cout << title << std::endl;
	strIdx++;
	//std::cout<<std::endl;
	
	std::string stdDuration = "";
	std::string stdOctave = "";
	std::string beat = "";
	int valuePart = 0;
	while(s[strIdx]!=':' && s[strIdx] != '\0' )
	{
		if(s[strIdx]==',')
		{
			valuePart++;
			strIdx++;
		}
		if(valuePart == 0)
		{
			if(s[strIdx] >= '0' && s[strIdx]<='9')
				stdDuration+=s[strIdx];
		
		}
		else if(valuePart==1) 	
		{
			if(s[strIdx] >= '0' && s[strIdx]<='9')
				stdOctave+=s[strIdx];
		}
		else 
			beat+=s[strIdx];
		
		strIdx++;
	}
	//std::cout << stdDuration<<std::endl;
	//std::cout << stdOctave<<std::endl;
	//std::cout << beat<<std::endl;
	strIdx++;
	
	
	std::string dur = "";
	std::string strNote = "";
	std::string oct = "";
	bool noteFound = false;
	while(s[strIdx]!=':' && s[strIdx] != '\0' )
	{
		if(s[strIdx]==',')
		{

			int intDur = 0;
			
			
			if(dur!="")
			{
				intDur = std::stoi(dur);
			}
			else
			{
				intDur = std::stoi(stdDuration);
			}
			
			
			bool needPause = false;
			std::string filteredNote = "";
			for(int i =0; i < strNote.size();i++)
			{
				if(oct=="")
					oct=stdOctave;
				if((strNote[i]>='a' && strNote[i]<='z') || (strNote[i]>='A' && strNote[i]<='Z'))
				{
					filteredNote+=toupper(strNote[i]);
					if(filteredNote!="P")filteredNote+=oct;
				}
				if(strNote[i]=='_')
				{
					needPause=true;
				}
				if(strNote[i]=='#')
				{
					filteredNote+='s';
				}
				if(strNote[i]=='.')
				{
					intDur+=intDur/2;
				}
			}
			
			
			std::string convertedDuration = "";
			
			int tempDur = std::stoi(stdDuration);
			intDur*=2;
			std::cout << intDur << std::endl;
			if(intDur <= tempDur)
				convertedDuration = "dF";
			else if(intDur == tempDur*2)
				convertedDuration = "dH";
			else if(intDur == tempDur*4)
				convertedDuration = "dQ";
			else
				convertedDuration = "dQH";
				
				
			if(filteredNote.size()==1 && filteredNote!="P")
				filteredNote+=stdOctave;
			myFile << "\tp.play( note{ note::"<<filteredNote<< ", note::"<<convertedDuration<<" } );\n";
			if(needPause)
				myFile << "\tp.play( note{ note::P, note::"<<convertedDuration<<" } );\n";
			
			dur="";
			strNote="";
			oct="";
			noteFound = false;
		}
		else
		{
			if(!noteFound && (s[strIdx]>='0' && s[strIdx] <='9'))
			{
				dur+=s[strIdx];
			}
			else if(!(s[strIdx]>='0' && s[strIdx] <='9'))
			{
				noteFound=true;
				strNote+=s[strIdx];
			}
			else
			{
				oct+=s[strIdx]-1;
			}
			
			
		}
		strIdx++;
	}
	
	myFile 	<< "}\n";

	//std::cout<<std::endl;
	
	
	myFile.close();
			
}



note_player_pc::~note_player_pc()
{
}

