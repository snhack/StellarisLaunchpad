/*
 * AnimatedGraphic.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef ANIMATEDGRAPHIC_H_
#define ANIMATEDGRAPHIC_H_

#include "stddef.h"
#include "Message.h"

class AnimatedGraphic: public Message {
	public:
	AnimatedGraphic(unsigned char *message, long messageLen, long numberOfFrames);
	~AnimatedGraphic();
	virtual void buffer(unsigned char *ptr);
	virtual long getLength();
	void* operator new(size_t size);
	void operator delete(void*);

	protected:

	unsigned char *_message;
	long _messageLen;
	long _numberOfFrames;
	long _frame;// the current frame
};

#endif /* ANIMATEDGRAPHIC_H_ */
