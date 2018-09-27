#include "hwlib.hpp"
#include <algorithm>
#include <cmath>

#include <array>
//#include <iostream>
#define START {64,32}

//namespace target = hwlib::target;

constexpr double radians_from_degrees(int degrees)
{
	return 2 * 3.14 * (degrees / 360.0);
}

constexpr int scaled_sine_from_degrees(int degrees)
{
	return 30 * ( 1.0 + sin(radians_from_degrees( degrees )));
}

constexpr int scaled_cos_from_degrees(int degrees)
{
	return 30 * ( 1.0 + cos(radians_from_degrees( degrees )));
}


class sine_lookup {
private:    
   int values[ 360 ] = {};
public: 
	
	constexpr sine_lookup() {
		for( int i = 0; i < 360; ++i ){
			values[ i ] = scaled_sine_from_degrees ( i );
		}
	}
	
	constexpr int get( int n ) const {
		return values[ n ];    
		}
};


class cos_lookup {
private:    
   int values[ 360 ] = {};
public: 
	
	constexpr cos_lookup() {
		for( int i = 0; i < 360; ++i ){
			values[ i ] = scaled_cos_from_degrees ( i );
		}
	}
	
	constexpr int get( int n ) const {
		return values[ n ];    
		}
};



void drawClock(sine_lookup sinusses, cos_lookup cosses, hwlib::window & oled)
{
	for(int i =0; i < 360; i+=30)
	{
		auto cirkel = hwlib::circle({32+(uint_fast16_t)cosses.get( i ),(uint_fast16_t)sinusses.get( i )},2);
		cirkel.draw(oled);
	}
}


void drawLine(hwlib::window & oled, hwlib::location end, hwlib::color col = hwlib::black )
{
	auto second = hwlib::line(START,end,col);
	second.draw(oled);
}


int main( void ){	
	
	constexpr sine_lookup sinusses = sine_lookup();
	constexpr cos_lookup cosses = cos_lookup();
	
	
	// kill the watchdog & wait for the PC console to start
	WDT->WDT_MR = WDT_MR_WDDIS;
	hwlib::wait_ms( 500 );   
	auto sclPin = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sdaPin = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2cBus = hwlib::i2c_bus_bit_banged_scl_sda(sclPin, sdaPin);
	auto oled = hwlib::glcd_oled_buffered(i2cBus);
	oled.clear();
	oled.flush();
	hwlib::wait_ms( 500 ); 
	
	drawClock(sinusses, cosses, oled);
	
	int secondCnt = 59;
	int minuteCnt = 59;
	int hourCnt = 11;
	
	hwlib::location hourEnd = {30+(uint_fast16_t)cosses.get( hourCnt*30 ),(uint_fast16_t)sinusses.get( hourCnt*30 )};
	hwlib::location minEnd = {30+(uint_fast16_t)cosses.get( minuteCnt*6 ),(uint_fast16_t)sinusses.get( minuteCnt*6 )};;
	hwlib::location secondEnd = {30+(uint_fast16_t)cosses.get( secondCnt*6 ),(uint_fast16_t)sinusses.get( secondCnt*6 )};
	
	auto MinuteButton 	= hwlib::target::pin_in(hwlib::target::pins::d5); //Button
	auto HourButton 	= hwlib::target::pin_in(hwlib::target::pins::d6); //Button
	auto oldTime = hwlib::now_us();
	auto currTime = oldTime;
	
	bool update = false;
	
	while(true){
		
		if(!MinuteButton.get())
		{
			minuteCnt++;
			update  = true;
		}
		if(!HourButton.get())
		{
			hourCnt++;
			update  = true;
		}
		currTime = hwlib::now_us();
		
		

		if(currTime - oldTime > 1000000 || update)
		{
			drawLine(oled, secondEnd, hwlib::white);
			secondCnt++;
			
			if(secondCnt > 59)
			{
				drawLine(oled, minEnd, hwlib::white);
				minuteCnt++;
				secondCnt = 0;
			}
			if(minuteCnt > 59)
			{
				minuteCnt = 0;
				drawLine(oled, hourEnd, hwlib::white);
				hourCnt++;
			}
			if(hourCnt > 11)
			{
				hourCnt=0;
			}
			
			hwlib::cout << hourCnt<<":"<<minuteCnt<<":"<< secondCnt<<"\n";
			if(minuteCnt<60 || update)
			{
				drawLine(oled, minEnd, hwlib::white);
				minEnd = {30+(uint_fast16_t)cosses.get( minuteCnt*6 ),(uint_fast16_t)sinusses.get( minuteCnt*6 )};
				
			}
			if(hourCnt<12 || update)
			{
				drawLine(oled, hourEnd, hwlib::white);
				hourEnd = {30+(uint_fast16_t)cosses.get( hourCnt*30 ),(uint_fast16_t)sinusses.get( hourCnt*30 )};
				
			}
					//hourEnd = {30+(uint_fast16_t)cosses.get( hourCnt*12 )-6,(uint_fast16_t)sinusses.get( hourCnt*12 )-6};
				
				//minEnd = {30+(uint_fast16_t)cosses.get( minuteCnt*6 )-3,(uint_fast16_t)sinusses.get( minuteCnt*6 )-3};
			
		
		
			secondEnd = {30+(uint_fast16_t)cosses.get( secondCnt*6 ),(uint_fast16_t)sinusses.get( secondCnt*6 )};
			
			drawLine(oled, secondEnd);
			drawLine(oled, minEnd);
			drawLine(oled, hourEnd);
			drawClock(sinusses, cosses, oled);
			oldTime = currTime;
			if(update)update=!update;
		}
		
		

		//hwlib::location minEnd = {30+(uint_fast16_t)cosses.get( minuteCnt*6 )-3,(uint_fast16_t)sinusses.get( minuteCnt*6 )-3};
		//hwlib::location hourEnd = {30+(uint_fast16_t)cosses.get( hourCnt*12 )-6,(uint_fast16_t)sinusses.get( hourCnt*12 )-6};
	
		//hwlib::wait_ms(1000);
	}
}