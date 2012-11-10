/*
 * RepeatedGraphic.h
 *
 *  Created on: 8 Nov 2012
 *      Author: tony
 */

#ifndef REPEATEDGRAPHIC_H_
#define REPEATEDGRAPHIC_H_

#include "stddef.h"
#include "GraphicMessage.h"

class RepeatedGraphic : public GraphicMessage {
	public:
	RepeatedGraphic(unsigned char *message, long messageLen, long repetitions);
	~RepeatedGraphic();
	virtual void buffer(unsigned char *ptr);
	virtual long getLength();
	void* operator new(size_t size);
	void operator delete(void*);
	private:
	long _repetitions;
};

#endif /* REPEATEDGRAPHIC_H_ */
