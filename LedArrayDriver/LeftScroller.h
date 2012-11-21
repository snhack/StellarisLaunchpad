/*
 * LeftScroller.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef LEFTSCROLLER_H_
#define LEFTSCROLLER_H_


#include "stddef.h"
#include "stdlib.h"
#include "Animation.h"
#include "Message.h"

class LeftScroller : public Animation {
	public:
		LeftScroller(LedArrayDriver &ledArray, Message &message, long repeats, unsigned char *displayBuffer);
		~LeftScroller();

		virtual void init();
		virtual long animate();

        void* operator new(size_t size);
        void operator delete(void*);
	private:
		Message &_message;
		//
		// The blank column counts so the message appears from the right.
		//
		long _prefixLen;
		long _prefix;
	};
#endif /* LEFTSCROLLER_H_ */
