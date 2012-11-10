/*
 * AsciiMessage.h
 *
 *  Created on: 7 Nov 2012
 *      Author: tony
 */

#ifndef ASCIIMESSAGE_H_
#define ASCIIMESSAGE_H_
#include "stddef.h"
#include "Message.h"

class AsciiMessage : public Message {
	public:
		AsciiMessage(char *message);
		~AsciiMessage();
		void buffer(unsigned char *ptr);
		long getLength();
        void* operator new(size_t size);
        void operator delete(void*);
	private:
		char *_message;
	};

#endif /* ASCIIMESSAGE_H_ */
