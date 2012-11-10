/*
 * LedArrayDriver.h
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */

#ifndef LEDARRAYDRIVER_H_
#define LEDARRAYDRIVER_H_

#include "PortPin.h"

#define PULSE_uSECS		10
#define LED_PAUSE		350
#define LED_FADE_PAUSE	100

class LedArrayDriver {
	public:
		LedArrayDriver(	PortPin *clock,
						PortPin *chipSelect,
						PortPin *shift,
						PortPin *a,
						PortPin *b,
						PortPin *c,
						unsigned char rows,
						unsigned short columns);
		~LedArrayDriver();

		void init();
		void clearDisplay();

		void begin();
		void show(unsigned char bits);
		void nextColumn();
		unsigned short numberOfColumns();
	private:
		PortPin *_clock;
		PortPin *_chipSelect;
		PortPin *_shift;
		PortPin *_a;
		PortPin *_b;
		PortPin *_c;
		unsigned char _rows;
		unsigned short _columns;
	};

#endif /* LEDARRAYDRIVER_H_ */
