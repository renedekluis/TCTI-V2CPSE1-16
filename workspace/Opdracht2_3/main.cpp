#include "hwlib.hpp"
#include "note_player_gpio.hpp"
//#include "fur_elise.hpp"
#include "rtttl_player.hpp"
#include "note_player.hpp"
#include "melody.hpp"



const char * testTuneA = "tester:d=4,o=5,b=140:8a5,8p,8a5,8p,8a5,8p,8a5,8p,8a_5,8p,8a_5,8p,8a_5,8p,8a_5,8p,";
const char * we_rock = "we-rock:d=4,o=6,b=140:32d#.5,32d.5,32d#.5,8f#.5,32g#.5,32f#.5,32f.5,32f#.5,8a#.5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,8f#.6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,16f5,32d#5,16d5,16d#5,4f#5,16g#5,16f#5,16f5,16f#5,4a#5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,4f#6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,8a#5,8b5,8c#6,8c#6,16d#6,16c#6,16b5,";

const char * SuperMar = "SuperMar:d=4,o=5,b=140:a,8f.,16c,16d,8f,f,16d,8c,8f,8f,8c6,8a.,g,8p,a,8f.,16c,16d,8f,f,16d,8c,8f,16a#,16a,16g,f,8p,8a.,8f.,8c,8a.,f,16g#,16f,8c,8g#.,g,8p,8a.,8f.,8c,8a.,f,16g#,16f,8c,c6";

const char* FUR_ELISE = "FurElise:d=8,o=5,b=125:32p,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,e,g#,b,4c.6,32p,e,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,d,c6,b,2a";

void f(auto &p){
	if(0){
		rtttl_play( p, SuperMar );
		//return 0;
	}
	hwlib::wait_ms( 3000 );
	if(1){
		auto fe = melody();
		fe.play( p );
		
		//return 0;
	}
}




int main( void ){	

	// kill the watchdog, wait for the PC console to start
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms( 1000 );   

	//const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
	//const char * we_rock = "we-rock:d=4,o=6,b=140:32d#.5,32d.5,32d#.5,8f#.5,32g#.5,32f#.5,32f.5,32f#.5,8a#.5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,8f#.6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,16f5,32d#5,16d5,16d#5,4f#5,16g#5,16f#5,16f5,16f#5,4a#5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,4f#6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,8a#5,8b5,8c#6,8c#6,16d#6,16c#6,16b5,";
	//const char * second = "21Second:d=4,o=6,b=140:8g5,8g5,8p,8g5,8g5,8p,8g5,8g5,8p,8g5,8g5,8g5,8p,8g5,8g5,8a_5,8d_5,8d_5,8p,8d_5,8d_5,8p,8d5,8d5,8p,8d5,8d5,8p,8f5,8g5,8g5";
	//const char * we_rock = "we-rock:d=4,o=6,b=140:32d#.5,32d.5,32d#.5,8f#.5,32g#.5,32f#.5,32f.5,32f#.5,8a#.5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,8f#.6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,16f5,32d#5,16d5,16d#5,4f#5,16g#5,16f#5,16f5,16f#5,4a#5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,4f#6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,8a#5,8b5,8c#6,8c#6,16d#6,16c#6,16b5,";


	note_player_pc pcPlayer;
	
	//pcPlayer.play_tune(we_rock);

	namespace target = hwlib::target;   
	auto lsp = target::pin_out( target::pins::d7 );
	auto p = note_player_gpio( lsp );
/*
	if(1){
		rtttl_play( p, testTuneA );
		//return 0;
	}

	if(1){
		auto fe = melody();
		fe.play( p );
		
		//return 0;
	}
*/
	while(true)
		f(p);
	return 0;
}
