/*
 * Message.h
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

class Message {
	public:
		virtual void buffer(unsigned char *ptr) = 0;
		virtual long getLength() = 0;
	};

#endif /* MESSAGE_H_ */
