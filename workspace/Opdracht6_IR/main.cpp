#include "hwlib.hpp"
#include "rtos.hpp"
#include "pause_detector.hpp"

int main( void ){	
	
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// wait for the PC console to start
	hwlib::wait_ms( 500 );
	
	namespace target = hwlib::target;
	
	auto resiever = target::pin_in( target::pins::d7 );      
	
	auto p = pause_detector(resiever);
	
	
	rtos::run();
}
