/*
 * StellarisPortPin.cpp
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#include "StellarisPortPin.h"

#define TRUE ((uint8_t)1)
#define FALSE ((uint8_t)0)

StellarisPortPin::StellarisPortPin(long portBase, volatile long pin) :
		_portBase(portBase), _pin(pin) {
}

StellarisPortPin::~StellarisPortPin() {
}

void StellarisPortPin::setAsOutput() {
	ROM_GPIOPinTypeGPIOOutput(_portBase, _pin);
}

void StellarisPortPin::setAsInput() {
	ROM_GPIOPinTypeGPIOInput(_portBase, _pin);
}

void StellarisPortPin::set() {
	ROM_GPIOPinWrite(_portBase, _pin, 0xFF);
}

void StellarisPortPin::set(unsigned char val) {
	long int mask = _pin | (_pin << 1) | (_pin << 2);
	ROM_GPIOPinWrite(_portBase, mask, val << 1);
}

void StellarisPortPin::clear() {
	ROM_GPIOPinWrite(_portBase, _pin, 0);
}

void StellarisPortPin::toggle() {
	if (read()) {
		clear();
	} else {
		set();
	}
}

long StellarisPortPin::read() {
	return ROM_GPIOPinRead(_portBase, _pin);
}

void StellarisPortPin::pulse(unsigned long micros) {
	toggle();
	ROM_SysCtlDelay((40 * micros) / 3);
	toggle();
}
