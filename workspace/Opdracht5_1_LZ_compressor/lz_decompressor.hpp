#pragma once

#include "match.hpp"

class lz_decompressor {
private:
	
	static const auto buffer_length = 100;
	std::array< char, buffer_length > arbuffer;
	char buffer[100000];
public: 
	
	template< typename F >
	void read_buffer(F read)
	{
		int i = 0;
		int k =0;
		for(;;)
		{
			auto ch = read();
			k=ch;
			if(ch == '\0')
				break;
			else{
				buffer[i] = ch;
				i++;
			}
		}
		std::cout <<"\n=====\t"<<k<<"\n";
	}
	
	template< typename S, typename D >
	void decompress( S read, D write ){
		
		int i=0;
		for(;;){
			std::cout << __LINE__ << "\n";
			read_buffer(read);
			std::cout << buffer <<"\n\n";
			std::cout << __LINE__ << "\n";
			char c = '\0';
			if( c == '\0' ){
				std::cout << __LINE__ << "\n";
				return;
			}
			std::cout << __LINE__ << "\n";
			if( c != '@' ){
				std::cout << __LINE__ << "\n";
				add( c, write );
			}
			else {
				std::cout << __LINE__ << "\n";
				int offset = read() - '0';
				int length = read() - '0';
				//std::cout << "add(match, write)";
				add( match( offset, length ), write );
				std::cout << __LINE__ << "\n";
			}
		} 
		std::cout << "EXIT decompress()!\n";
	}
	
	
	
	template< typename F >
	void add( char c, F write ){
		//std::cout << "\tIN - add(char, write)";
		write( c );
		std::cout << __LINE__ << "\n";
		for( int i = buffer_length; i > 0; --i ){
			arbuffer[ i ] = arbuffer[ i - 1 ];
		}
		std::cout << __LINE__ << "\n";
		arbuffer[ 0 ] = c;
	}
	
	
	template< typename F >   
	void add( match m, F write ){
		//std::cout << "\tIN - add(match, write)";
		while( m.length-- ){
			add( arbuffer[ m.offset ], write );
		}
	}
	
	
};
