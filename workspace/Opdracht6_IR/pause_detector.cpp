#include "pause_detector.hpp"

pause_detector::pause_detector(hwlib::target::pin_in & pin):
	task( 10, "pause_detector" ),
	pin(pin),
	pauses( this, "pauses" ),
	irReciever(ir_receiver(pin)),
	msgDec(msg_decoder(pauses)),
	sample_clock( this, 100, "sample_clock") // 100 * 1000 == om de waarde in milisec te zetten
{
	timestamps[0] = 0;
	timestamps[1] = 0;
}

void pause_detector::main()
{
	for(;;)
	{
		auto event = wait(sample_clock);
		if( event == sample_clock ){
			getPause();	
		 }
	}	
}

void pause_detector::getPause()
{
	int absoluteSignal = irReciever.getPause();
	if(currentSignal != absoluteSignal)
	{
		if(currentSignal == 0)
		{
			timestamps[0] = hwlib::now_us();
		}
		else
		{
			timestamps[1] = hwlib::now_us();
			int pause_time = (timestamps[1]-timestamps[0]);
			pause_detected(pause_time);
		}
		currentSignal = absoluteSignal;
	}
}

void pause_detector::pause_detected(int n)
{
	pauses.write(n);
	msgDec.bufferSize+=1;
}

pause_detector::~pause_detector()
{
}

