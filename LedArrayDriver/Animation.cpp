/*
 * Animation.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include "Animation.h"

Animation::Animation(LedArrayDriver &ledArray, long repeats)
	:	_ledArray(ledArray),
		_displayIndex(0),
		_repeats(repeats),
		_repeatCount(0) {
	//
	// Clear the buffer
	//
	for(int i = 0;i < BUFFERSIZE;i++) {
		_displayBuffer[i] = 0;
	}
}

Animation::~Animation() {

}
