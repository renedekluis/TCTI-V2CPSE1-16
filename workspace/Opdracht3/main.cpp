#include "hwlib.hpp"
#include "message.hpp"

extern "C" char convert_char(char c);
/*
char convert(char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		c+=32;
	}
	else if(c >= 'a' && c <= 'z')
	{
		c-=32;
	}
	return c;
}*/

extern "C" void uart_put_char( char c ){
	c = convert_char(c);
	hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();




int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 500 );

   application();
   
   while(true);
   return 0;
}