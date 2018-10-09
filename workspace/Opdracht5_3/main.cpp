
#include "hwlib.hpp"
//#include "compressor.hpp" 
//#include "decompressor.hpp" 


/*
 * 2.	Pas de aanroep van de LZ compressor/encoder aan,
 * 		zodat er een assembler file wordt gegenereerd 
 * 		die de gecodeerde characters bevat (en die in een volgende stap meegenomen kan worden in een Due applicatie).
 * 
 */
 
extern "C" void uart_put_char( char c ){
	hwlib::cout << c;
}

extern "C" void debug( char c ){
	hwlib::cout << "[" << c << "]" ;
}
extern "C" void print_asciz( const char * s );

extern "C" void decompress();

extern "C" void decompressor();


//extern "C" void speeltuin_decompress();


int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
	hwlib::wait_ms( 500 );
	decompressor();
	hwlib::cout<<"\n\n\n";
	decompress();
	//speeltuin_decompress();
	
	hwlib::cout <<"\n\nend of program";
}