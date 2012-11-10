/*
 * AnimatedGraphic.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include "string.h"
#include "stdlib.h"
#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(unsigned char *message, long messageLen, long numberOfFrames)
	:_message(message),_messageLen( messageLen), _numberOfFrames(numberOfFrames),_frame(0){}

void AnimatedGraphic::buffer(unsigned char *dest) {
	long start = (_frame*_messageLen);

	for(long i = start;i< (start+_messageLen) ;i++) {
		unsigned char letter = _message[i];
		*dest++ = letter;
	}
	_frame++;
	if(_frame == _numberOfFrames) {
		_frame = 0;
	}
}

long AnimatedGraphic::getLength() {
	return _messageLen;
}

void* AnimatedGraphic::operator new(size_t size) {
	return calloc(size, (size_t)1);
}

void AnimatedGraphic::operator delete(void* ptr) {
	free(ptr);
}
