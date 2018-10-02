#pragma once


#include "match.hpp"

template< int N >
class lz_compressor {
private:

	
public:
	char buffer[ N ];
	int used;
	//lz_compressor();
	
	template< typename F >
	void read_buffer( F read ){
		used = 0;
		for(;;){
			char c = (char)read();
			if( used == N ){
				std::cerr << "buffer overflow";
				break;
			}
			if( c == '@' ){
				std::cerr << "text contains @";
				break;
			}
			if( c == '\0' ){
				break;
			}
			buffer[ used++ ] = c;
		}
	}
	
	
	template< typename F >
	void write_compressed_buffer( F write ){
		for( int i = 0; i < used; ){
			auto match = find( i );
			
			if( match.length >= 3 ){    
				//std::cout <<  "[@"<<'0'-match.offset<<","<< '0'-match.length <<"]";
				write( '@' );
				write( '0' - match.offset );
				write( '0' + match.length );
				i += match.length;
			}
			else{
				//std::cout << buffer[i];
				write( buffer[ i++ ] );
			}
		}
	}
	
	
	
	// find the best match in the buffer (40 positions back, upto index) 
	// for the string starting at index
	match find( int index ){
		auto best = match( 0 );
		for( int i = std::max( 0, index  ); i < index - 1; ++i ){
			auto length = count_identical_prefix_length( i, index );
			//auto length = std::min(40,count_identical_prefix_length( i, index ));
			best = std::max( best, match( index - i - 1, length ) );
		}
		return best;
	} 

	
	// return the length of the longest identical prefix of s and p
	int count_identical_prefix_length( int s, int p ){
		int result = ( ( s > N ) || ( buffer[ s ] != buffer[ p ] )) ? 0  : 1 + count_identical_prefix_length( s + 1, p + 1 );
		return result;
	}   
	
	
	
	
	
	template< typename S, typename D >
	void compress( S read, D write ){
		read_buffer( read );
		//std::cout << buffer;
		write_compressed_buffer( write );
	}
	
	//~lz_compressor();
};