/*
 * GraphicMessage.cpp
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#include "string.h"
#include "stdlib.h"
#include "GraphicMessage.h"

GraphicMessage::GraphicMessage(unsigned char *message, long messageLen):_message(message),_messageLen(messageLen){}

void GraphicMessage::buffer(unsigned char *dest) {
	for(long i = 0;i<_messageLen;i++) {
		unsigned char letter = _message[i];
		*dest++ = letter;
	}
}

long GraphicMessage::getLength() {
	return _messageLen;
}

void* GraphicMessage::operator new(size_t size) {
	return calloc(size, (size_t)1);
}

void GraphicMessage::operator delete(void* ptr) {
	free(ptr);
}
