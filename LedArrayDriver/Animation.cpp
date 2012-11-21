/*
 * Animation.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include "Animation.h"

Animation::Animation(LedArrayDriver &ledArray, long repeats, unsigned char *displayBuffer)
	:	_ledArray(ledArray),
		_displayIndex(0),
		_repeats(repeats),
		_repeatCount(0),
		_displayBuffer(displayBuffer) {
}

Animation::~Animation() {

}

void Animation::init() {
	//
	// Clear the buffer
	//
	for(int i = 0;i < BUFFERSIZE;i++) {
		_displayBuffer[i] = 0;
	}

}
