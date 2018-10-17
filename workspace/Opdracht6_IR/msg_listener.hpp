#pragma once


class msg_listener
{
private:
	
public:
	virtual char* bitValueDecoder(int bitValue) = 0;
	virtual void msg_received(char* m) = 0;
};

