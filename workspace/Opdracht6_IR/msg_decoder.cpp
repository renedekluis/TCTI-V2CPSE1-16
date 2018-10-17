#include "msg_decoder.hpp"

msg_decoder::msg_decoder(rtos::channel< int, 1024 > &pauses):
	task( 20, "msg_decoder" ),
	messages( this, "messages" ),
	pauses( pauses ),
	decoder_loop_clock( this, 50 *1000 , "decode_clock"),
	msgLog(msg_logger(messages))
{
}

void msg_decoder::main()
{
	for(;;)
	{
		auto event = wait(decoder_loop_clock);
		if( event == decoder_loop_clock )
		{
			while(bufferSize>0)
			{
				int channelItem = readFromPauseChannel();
				
				if(channelItem>4000 && channelItem <5000) //4400 tot 4600 voor kleinere scope
				{
					filling = true;
				}
				
				if(filling)
				{
					bufferstring[used] = channelItem;
					used++;
				}
				
				if(used >= 32)
				{
					pressedButton=0;
					for(int i = 0; i < used; i++)
					{
						if( i >0 && i <= 8 )
						{
							if(!(bufferstring[i]>200 && bufferstring[i]<1000))
							{
								used=0;
								filling=false;
								break;
							}
						}
						if( i > 8 && i <= 16 )
						{
							if(!(bufferstring[i]>1000 && bufferstring[i]<2000))
							{
								used=0;
								filling=false;
								break;
							}
						}
						if(i>16)
						{
							if(bufferstring[i]>1000 && bufferstring[i]<2000)
							{
								pressedButton = pressedButton << 1;
								pressedButton |= 1;
							}
							else if(bufferstring[i]>200 && bufferstring[i]<1000 )
							{
								pressedButton = pressedButton << 1;
								pressedButton |= 0;
							}
						}
					}
					if(filling)
					{
						msg_received(bitValueDecoder(pressedButton));
						used = 0;
						filling = false;
					}
				}
			}
		}
	}
}

void msg_decoder::msg_received(char* m)
{
	messages.write(m);
	msgLog.bufferSize+=1;
}


char* msg_decoder::bitValueDecoder(int bitValue)
{
	char *result = (char*)"X";
	switch(bitValue)
	{
		case 12622:
			result = (char*)"up";
			break;
		case 21547:
			result = (char*) "down";
			break;
		case 4462:
			result = (char*) "left";
			break;
		case 24862:
			result = (char*) "right";
			break;
		case 382:
			result = (char*) "ok";
			break;
		case 13387:
			result = (char*) "1";
			break;
		case 19507:
			result = (char*) "2";
			break;
		case 22567:
			result = (char*) "3";
			break;
		case 6247:
			result = (char*) "4";
			break;
		case 3187:
			result = (char*) "5";
			break;
		case 15682:
			result = (char*) "6";
			break;
		case 2167:
			result = (char*) "7";
			break;
		case 7267:
			result = (char*) "8";
			break;
		case 11602:
			result = (char*) "9";
			break;
		case 9562:
			result = (char*) "0";
			break;
		case 8542:
			result = (char*) "*";
			break;
		case 10582:
			result = (char*) "#";
			break;
		default:
			result = (char*) "X";
			break;
	}
	return result;
}

int msg_decoder::readFromPauseChannel()
{	
	int result =0;
	if(bufferSize > 0)
	{
		result = pauses.read();
		bufferSize-=1;
	}
	
	return result;
}



msg_decoder::~msg_decoder()
{
}

