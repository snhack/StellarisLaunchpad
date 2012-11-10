/*
 * StellarisPortPin.h
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */

#ifndef STELLARISPORTPIN_H_
#define STELLARISPORTPIN_H_

#include "PortPin.h"

class StellarisPortPin : public PortPin {
public:
	StellarisPortPin(long portBase, volatile long pin);
	~StellarisPortPin();

	virtual void setAsOutput();
	virtual void setAsInput();
	virtual void set();
	virtual void set(unsigned char val);
	virtual void clear();
	virtual long read();
	virtual void toggle();
	virtual void pulse(unsigned long micros);
private:
	long _portBase;
	long _pin;
};

#endif /* STELLARISPORTPIN_H_ */
