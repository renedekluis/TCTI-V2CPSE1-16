
#include "hwlib.hpp"
#include "note_player_gpio.hpp"
//#include "fur_elise.hpp"
#include "rtttl_player.hpp"
#include "melody.hpp"


int main( void ){	

	// kill the watchdog, wait for the PC console to start
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms( 1000 );   

	namespace target = hwlib::target;   
	auto lsp = target::pin_out( target::pins::d7 );
	auto p = note_player_gpio( lsp );

	auto fe = melody();
	fe.play( p );

	return 0;
}