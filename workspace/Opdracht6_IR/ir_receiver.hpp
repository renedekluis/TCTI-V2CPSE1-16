#pragma once

#include "hwlib.hpp"

class ir_receiver
{
private:
	hwlib::target::pin_in &ir_pin;
public:
	ir_receiver(hwlib::target::pin_in & ir_pin);
	int getPause();
	~ir_receiver();

};

