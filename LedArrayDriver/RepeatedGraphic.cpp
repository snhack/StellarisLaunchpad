/*
 * RepeatedGraphic.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include <string.h>
#include <stdlib.h>
#include "RepeatedGraphic.h"

RepeatedGraphic::RepeatedGraphic(unsigned char *message, long messageLen, long repetitions)
	:GraphicMessage(message,messageLen),_repetitions(repetitions){}

void RepeatedGraphic::buffer(unsigned char *dest) {
	for(long j = 0; j < _repetitions; j++) {
		for(long i = 0;i<_messageLen;i++) {
			unsigned char letter = _message[i];
			*dest++ = letter;
		}
		*dest++ = 0;
	}
}

long RepeatedGraphic::getLength() {
	return (_messageLen + 1) * _repetitions;
}

void* RepeatedGraphic::operator new(size_t size) {
	return calloc(size, (size_t)1);
}

void RepeatedGraphic::operator delete(void* ptr) {
	free(ptr);
}
