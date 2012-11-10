/*
 * GraphicMessage.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef GRAPHICMESSAGE_H_
#define GRAPHICMESSAGE_H_

#include "stddef.h"
#include "Message.h"

class GraphicMessage : public Message {
	public:
	GraphicMessage(unsigned char *message, long messageLen);
	~GraphicMessage();
	virtual void buffer(unsigned char *ptr);
	virtual long getLength();
	void* operator new(size_t size);
	void operator delete(void*);
	protected:
	unsigned char *_message;
	long _messageLen;
};

#endif /* GRAPHICMESSAGE_H_ */
