/*
 * Animation.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "LedArrayDriver.h"

#define BUFFERSIZE 1000


class Animation {
	public:
		Animation(LedArrayDriver &ledArray, long repeats, unsigned char *displayBuffer);
		~Animation();
		virtual void init();
		virtual long animate() = 0;
	protected:
		unsigned char *_displayBuffer;
		LedArrayDriver &_ledArray;
		long _displayIndex;
		long _repeats;
		long _repeatCount;
	};


#endif /* ANIMATION_H_ */
