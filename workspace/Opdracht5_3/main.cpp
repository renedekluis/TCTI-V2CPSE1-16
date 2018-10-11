
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




extern "C" void make_string();


int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
	// wait for the PC console to start
	hwlib::wait_ms( 500 );
	make_string();
	
	hwlib::cout <<"\n\nend of program";
}