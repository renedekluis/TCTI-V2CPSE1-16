#pragma once
#include "rtos.hpp"
#include "hwlib.hpp"
#include "msg_listener.hpp"

class msg_logger : public rtos::task<>
{
private:
	rtos::channel< char*, 1024 > &messages;
	rtos::timer clear_display_timer;
	
	hwlib::target::pin_oc sclPin; 
	hwlib::target::pin_oc sdaPin;
	hwlib::i2c_bus_bit_banged_scl_sda i2cBus;
	hwlib::glcd_oled_buffered oled;
	char* oldCommand = (char*)"X";
	hwlib::window_part w1 = hwlib::window_part(oled, hwlib::location(0,10),hwlib::location(128,64));
	hwlib::font_default_16x16 f1 = hwlib::font_default_16x16();
	bool cleared = false;
	void main();
	
public:
	msg_logger(rtos::channel< char*, 1024 >& messages);
	int bufferSize = 0;
	
	char* ReadMessage();
	void WriteMessage(char* ch);
	~msg_logger();

};

