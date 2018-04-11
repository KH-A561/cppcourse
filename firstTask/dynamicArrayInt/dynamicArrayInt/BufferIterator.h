#pragma once
#include "CircularBuffer.h"

class BufferIterator
{
private:
	CircularBuffer queue;
	int flag;

public:
	BufferIterator(CircularBuffer& queue);

	void start();

	void next();

	bool finish();

	int getValue();
};

