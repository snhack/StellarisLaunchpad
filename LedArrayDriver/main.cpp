/*
* LedArrayDriver.cpp
*
* Created: 29/08/2012 21:07:41
*  Author: tony walmsley
*/
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "StellarisLaunchpad.h"
#include "StellarisPort.h"
#include "StellarisPortPin.h"
#include "LedArrayDriver.h"
#include "Message.h"
#include "AsciiMessage.h"
#include "RepeatedGraphic.h"
#include "AnimatedGraphic.h"
#include "LeftScroller.h"
#include "StaticDisplay.h"
#include "GraphicBitmaps.h"

#define NBR_OF_DISPLAY_COLUMNS  80
#define NBR_OF_DISPLAY_ROWS		7

//
// Fix a compile error - see http://stackoverflow.com/questions/920500/what-is-the-purpose-of-cxa-pure-virtual for details.
//
// extern "C" void __cxa_pure_virtual() { while (1); }
//
// The main entry point
//
int main(void) {
	//
	// Board and port initialisations
	//
	StellarisLaunchpad pad;
	StellarisPort port1(SYSCTL_PERIPH_GPIOD);
	StellarisPort port2(SYSCTL_PERIPH_GPIOE);
	//
	// Create a set of objects representing the output pins
	//
	StellarisPortPin clock(GPIO_PORTD_BASE, GPIO_PIN_1);
	StellarisPortPin shift(GPIO_PORTD_BASE, GPIO_PIN_2);
	StellarisPortPin chipSelect(GPIO_PORTD_BASE, GPIO_PIN_3);
	StellarisPortPin a(GPIO_PORTE_BASE, GPIO_PIN_1);
	StellarisPortPin b(GPIO_PORTE_BASE, GPIO_PIN_2);
	StellarisPortPin c(GPIO_PORTE_BASE, GPIO_PIN_3);

	//
	// Create and initialise the LedArrayDriver
	//
	LedArrayDriver led(&clock, &chipSelect, &shift, &a,&b,&c, NBR_OF_DISPLAY_ROWS, NBR_OF_DISPLAY_COLUMNS);
	led.init();

	AsciiMessage welcome("**** Welcome to the Swindon Hackspace at the Museum of Computing - Wednesdays 6:30pm to 10pm ****");
	RepeatedGraphic multiInvader(invader, 10, 8);
	AnimatedGraphic pacman(animPacman, 17, 7);// columns * frames
	AnimatedGraphic invader(animInvader, 11, 4);// columns * frames

	LeftScroller scrollLeft1(led, invader, 2);
	LeftScroller scrollLeft2(led, multiInvader, 1);
	LeftScroller scrollLeft3(led, pacman, 1);
	LeftScroller scrollLeft4(led, welcome, 1);
	do
	{
		while(scrollLeft1.animate());
		while(scrollLeft2.animate());
		while(scrollLeft3.animate());
		while(scrollLeft4.animate());
	} while(1);
}
