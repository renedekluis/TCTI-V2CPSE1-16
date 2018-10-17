#include "ir_receiver.hpp"

ir_receiver::ir_receiver(hwlib::target::pin_in & ir_pin):
	ir_pin(ir_pin)
{
}

int ir_receiver::getPause()
{
	return ir_pin.get();
}

ir_receiver::~ir_receiver()
{
}

