#pragma once
#include "msg_decoder.hpp"
#include "ir_receiver.hpp"
#include "pause_listener.hpp"
#include "hwlib.hpp"
#include "rtos.hpp"



class pause_detector : public rtos::task<>, public pause_listener
{
private:
	hwlib::pin_in & pin;
	rtos::channel< int, 1024 > pauses;

	ir_receiver irReciever;
	msg_decoder msgDec;
	rtos::clock sample_clock;
	bool pauseFound = false;
	bool signalFound = false;
	int timestamps[2];
	int currentSignal = 1;
	void main();
	
public:
	pause_detector(hwlib::target::pin_in & pin);
	void getPause();
	void pause_detected(int n);
	~pause_detector();

};

