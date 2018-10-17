#include "msg_logger.hpp"


#define SCL hwlib::target::pins::scl
#define SDA hwlib::target::pins::sda

msg_logger::msg_logger(rtos::channel< char*, 1024 >& messages):
	task( 30, "msg_logger" ),
	messages(messages),
	clear_display_timer( this, "cdt"),
	sclPin(hwlib::target::pin_oc(SCL)),
	sdaPin(hwlib::target::pin_oc(SDA)),
	i2cBus(hwlib::i2c_bus_bit_banged_scl_sda(sclPin, sdaPin)),
	oled(hwlib::glcd_oled_buffered(i2cBus))
{
	oled.clear();
}


void  msg_logger::main()
{
	
	for(;;){
		char* buttonChar =ReadMessage();
		
		if(bufferSize<=0)
		{
			clear_display_timer.set(5*1000*1000);
			wait(clear_display_timer);
			oled.clear();
			oled.flush();
		}
		else
		{
			if(buttonChar!=(char*)"X")
			{
				WriteMessage(buttonChar);
			}
			bufferSize-=1;
		}
	}
}

char* msg_logger::ReadMessage()
{
	char* temp = (char*)"X";
	if(bufferSize > 0)
	{
		temp = messages.read();
		hwlib::cout << temp << "\n";
		
	}
	return temp;
}
void msg_logger::WriteMessage(char* ch)
{
		hwlib::window_ostream d1 = hwlib::window_ostream(w1, f1);
		oled.clear();
		d1 << "\f" << ch;
		oled.flush();
}

msg_logger::~msg_logger()
{
}

