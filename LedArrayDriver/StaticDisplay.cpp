/*
 * StaticDisplay.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include "StaticDisplay.h"

StaticDisplay::StaticDisplay(LedArrayDriver &ledArray, Message &message,
		long repeats, unsigned char *displayBuffer) :
		Animation(ledArray, repeats, displayBuffer), _message(message) {
}

StaticDisplay::~StaticDisplay() {

}

void StaticDisplay::init() {
	Animation::init();
	_message.buffer(_displayBuffer);
}

long StaticDisplay::animate() {
	//
	// Set up and clock-in the first shift register bit
	//
	_ledArray.begin();
	//
	// Process each column in the buffer
	//
	long count = 0;
	while (count <= _ledArray.numberOfColumns()) {
		unsigned char pattern = _displayBuffer[count];
		_ledArray.show(pattern);
		_ledArray.nextColumn();
		count++;
	}
	if (_repeatCount++ == _repeats) {
		init();
		_repeatCount = 0;
		return 0;
	}
	return 1;
}

void* StaticDisplay::operator new(size_t size) {
	return calloc(size, (size_t) 1);
}

void StaticDisplay::operator delete(void* ptr) {
	free(ptr);
}
