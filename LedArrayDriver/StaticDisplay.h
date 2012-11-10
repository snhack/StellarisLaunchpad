/*
 * StaticDisplay.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef STATICDISPLAY_H_
#define STATICDISPLAY_H_

#include "stddef.h"
#include "stdlib.h"
#include "Animation.h"
#include "Message.h"

class StaticDisplay : public Animation {
	public:
	StaticDisplay(LedArrayDriver &ledArray, Message &message, long repeats);
	~StaticDisplay();

	virtual void init();
	virtual long animate();

	void* operator new(size_t size);
	void operator delete(void*);
	private:
	Message &_message;
};
#endif /* STATICDISPLAY_H_ */
