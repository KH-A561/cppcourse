#include "stdafx.h"
#include "BufferIterator.h"


BufferIterator::BufferIterator(CircularBuffer& queue)
{
	this->queue = queue;
}

void BufferIterator::start()
{
	flag = 0;
}

void BufferIterator::next()
{
	flag++;
}

bool BufferIterator::finish()
{
	if (flag >= queue.getLength()) {
		return true;
	}
	return false;
}

int BufferIterator::getValue()
{
	return queue.top();
}

