//#include "hwlib.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include "lz_compressor.hpp"
#include "lz_decompressor.hpp"

/*
 * Neem de LZ encoder en breidt die uit met een decompressor/decoder 
 * (in C++, op de PC) die zijn uitvoer (via en lambda parameter) naar std::cout schrijft.
 * 
 */
 
#define INPUTFILE "../textfile.txt"
#define OUTPUTFILE "../textOutputFile.txt"



int main( void ){	

	
	lz_compressor< 4096 > compressor;

	std::ifstream f1;
	f1.open( INPUTFILE );
	if( ! f1.is_open()){
		std::cerr << "input file not opened";
		return -1;      
	}

	std::ofstream f2;
	f2.open( OUTPUTFILE );
	if( ! f2.is_open()){
		std::cerr << "output file not opened";
		return -1;      
	}

	compressor.compress( 
		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
		[ &f2 ]( char c ){ f2.put( c ); } 
	);
	
	
	f2.close();
	
	std::ifstream f3;
	f3.open( OUTPUTFILE );
	if( ! f3.is_open()){
		std::cerr << "input file not opened";
		return -1;      
	}
	
	std::ofstream f4;
	f4.open( "../rubbish.txt" );
	if( ! f4.is_open()){
		std::cerr << "output file not opened";
		return -1;      
	}
	
	lz_decompressor decompressor;
	
	decompressor.decompress( 
		[ &f3 ]()-> int { auto c = f3.get(); return f3.eof() ? '\0' : c; },
		[ &f4 ]( char c ){ f4.put( c ); } 
	);
	
	//decompressor.decompress(
	//	[ &f3 ]()-> int { auto c = f3.get(); return f3.eof() ? '\0' : c; },
	//	[](char c){ std::cout << c;});

	return 0;
}
