#include "hwlib.hpp"
#include "note_player_gpio.hpp"
//#include "fur_elise.hpp"
#include "rtttl_player.hpp"
#include "note_player.hpp"
#include "melody.hpp"



const char * testTuneA = "tester:d=4,o=5,b=140:8a5,8p,8a5,8p,8a5,8p,8a5,8p,8a_5,8p,8a_5,8p,8a_5,8p,8a_5,8p,";

const char * we_rock = "we-rock:d=4,o=6,b=140:32d#.5,32d.5,32d#.5,8f#.5,32g#.5,32f#.5,32f.5,32f#.5,8a#.5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,8f#.6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,16f5,32d#5,16d5,16d#5,4f#5,16g#5,16f#5,16f5,16f#5,4a#5,16b5,16a#5,16a5,16a#5,16f6,16d#6,16d6,16d#6,16f6,16d#6,16d6,16d#6,4f#6,8d#6,8f#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8d#6,32c#6,32d#6,16f6,8d#6,8c#6,8c6,4a#5,8a#5,8b5,8c#6,8c#6,16d#6,16c#6,16b5,";

const char * SuperMar = "SuperMar:d=4,o=5,b=140:a,8f.,16c,16d,8f,f,16d,8c,8f,8f,8c6,8a.,g,8p,a,8f.,16c,16d,8f,f,16d,8c,8f,16a#,16a,16g,f,8p,8a.,8f.,8c,8a.,f,16g#,16f,8c,8g#.,g,8p,8a.,8f.,8c,8a.,f,16g#,16f,8c,c6";
const char* Toxicity = "Toxicity:d=4,o=5,b=125:g,8p,16g,16g,8d#.,16c,g,8p,16g,16g,8d#.,16c,8g,2d#,8c,8g,2d,8p,g,8p,8g,8g,8g,8g,8g,8g,8g,8a#,8g,8d#,d#,8f,8d#,8d#,16d,16d#,16d,16c,2d,2d#.,2d#,16g#,16g#,16g#,8g#,g#,8a#,8g#,8g#,2d,8p,8c,8g,2d#,8c,8g,2d#,8c,g#,a#,8g#,8g";
const char* FUR_ELISE = "FurElise:d=8,o=5,b=125:32p,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,e,g#,b,4c.6,32p,e,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,d,c6,b,2a";


int main( void ){	

	// kill the watchdog, wait for the PC console to start
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms( 1000 );   

	note_player_pc pcPlayer;
	
	pcPlayer.play_tune(we_rock);

	return 0;
}
