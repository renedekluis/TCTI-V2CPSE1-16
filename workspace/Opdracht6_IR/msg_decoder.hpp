#pragma once

#include "msg_listener.hpp"
#include "msg_logger.hpp"
#include "hwlib.hpp"
#include "rtos.hpp"


class msg_decoder : public rtos::task<>, public msg_listener
{
private:
	msg_listener * listeners;
	rtos::channel< char*, 1024 > messages;
	rtos::channel< int, 1024 > &pauses;
	rtos::clock decoder_loop_clock;
	msg_logger msgLog;
	int bufferstring[40];
	int bitstring[32];
	int pressedButton =0;
	
	int used = 0;
	bool filling = false;
	
	void main();
public:
	int bufferSize = 0;
	msg_decoder(rtos::channel< int, 1024 >& pauses);
	char* bitValueDecoder(int bitValue);
	int readFromPauseChannel();
	void writeToMessageChannel(int i);
	void msg_received(char* m);
	~msg_decoder();

};

