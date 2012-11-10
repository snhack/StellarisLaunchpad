/*
 * LedArrayDriver.cpp
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */
#include "inc/hw_types.h"
#include "LedArrayDriver.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

LedArrayDriver::LedArrayDriver(	PortPin *clock,
								PortPin *chipSelect,
								PortPin *shift,
								PortPin *a,
								PortPin *b,
								PortPin *c,
								unsigned char rows,
								unsigned short columns)
	:	_clock(clock),
		_chipSelect(chipSelect),
		_shift(shift),
		_a(a),
		_b(b),
		_c(c),
		_rows(rows),
		_columns(columns) {

}

LedArrayDriver::~LedArrayDriver() {
}

void LedArrayDriver::init() {
	_clock->setAsOutput();
	_clock->clear();
	_chipSelect->setAsOutput();
	_chipSelect->clear();
	_shift->setAsOutput();
	_shift->clear();
	_a->setAsOutput();
	_a->clear();
	_b->setAsOutput();
	_b->clear();
	_c->setAsOutput();
	_c->clear();

	clearDisplay();
}

void LedArrayDriver::clearDisplay() {
	_shift->clear();
	for(unsigned short col = 0;col <_columns;col++) {
		_clock->pulse(PULSE_uSECS);
	}
}

void LedArrayDriver::begin() {
	_shift->set();
	_clock->pulse(PULSE_uSECS);
	_shift->clear();
}

void LedArrayDriver::nextColumn() {
	_clock->pulse(PULSE_uSECS);
}

void LedArrayDriver::show(unsigned char bits) {

	for(unsigned char row = 1; row <= _rows; row++) {
		if(bits & 1<<(row-1)) {
			//
			// The bit is set so light the LED in the row
			//
			_a->set(row);
		}
		ROM_SysCtlDelay(LED_PAUSE);
	}
	//
	// Clear the column and move to the next one
	//
	_a->set(0);
	ROM_SysCtlDelay(LED_FADE_PAUSE);
}

unsigned short LedArrayDriver::numberOfColumns() {
	return _columns;
}
