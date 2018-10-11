#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 


/*
 * 2.	Pas de aanroep van de LZ compressor/encoder aan,
 * 		zodat er een assembler file wordt gegenereerd 
 * 		die de gecodeerde characters bevat (en die in een volgende stap meegenomen kan worden in een Due applicatie).
 * 
 */
 
 
 int create_asm_file()
 {
	std::ifstream f1;
	f1.open("../compressed.txt");
	if(!f1.is_open()){
		std::cerr << "inputfile not opened.\n";
		return -1;
	}
	
	
	 
	std::ofstream f2;
	f2.open( "../compressed.asm" );
	if( ! f2.is_open()){
		std::cerr << "output file not opened.\n";
		return -1;      
	}
	
	f2 << "\t.global string\n\n"
		<< "\nstring:\n"
		<< "\t.ascii \"";
	for(;;)
	{
		auto ch = f1.get();
		
		if(ch == f1.eof())
		{
			std::cout << "EOF FOUND\n";
			break;
		}
		else if(ch == -1)
		{
			std::cout << "-1 FOUND\n";
			break;
		}
		else if(ch == '\n')
		{
			f2 	<< " \"\n"
				<< "\t.ascii \"";
		}
		else
		{
			f2 << (char)ch;
		}
	}
	
	f2 << "\"\n";
	
	f2.close();
	
	return 0;
 }

int main( void ){	
	lz_compressor< 4096 > compressor;
	
	std::ifstream f1;
	f1.open( "../textfile.txt" );
	if( ! f1.is_open()){
		std::cerr << "input file not opened";
		return -1;      
	}
   
	std::ofstream f2;
	f2.open( "../compressed.txt" );
	if( ! f2.is_open()){
		std::cerr << "output file not opened";
		return -1;      
	}
	
	compressor.compress( 
		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
		[ &f2 ]( char c ){ f2.put( c ); }
	);
	
	f1.close();
	f2.close();
	
	
	create_asm_file();
	
	f1.open( "../compressed.txt" );
	if( ! f1.is_open()){
		std::cerr << "compressed file not opened";
		return -1;      
	}   
	
	f1.close();
	
	
}