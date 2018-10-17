#pragma once

#include "rtos.hpp"


class pause_listener
{
private:
	
	
public:
	virtual void getPause() =0;
	virtual void pause_detected(int n) = 0;
};

