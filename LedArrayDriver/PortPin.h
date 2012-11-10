/*
 * PortPin.h
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */

#ifndef PORTPIN_H_
#define PORTPIN_H_

class PortPin {
	public:
		PortPin();
		~PortPin();

		virtual void setAsOutput() = 0;
		virtual void setAsInput() = 0;
		virtual void set() = 0;
		virtual void set(unsigned char val) = 0;
		virtual void clear() = 0;
		virtual long read() = 0;
		virtual void toggle() = 0;
		virtual void pulse(unsigned long micros) = 0;
};

#endif /* PORTPIN_H_ */
