#include "stdafx.h"
#include "BufferIterator.h"


BufferIterator::BufferIterator()
{
}

BufferIterator::BufferIterator(CircularBuffer& queue)
{
	this->queue = &queue;
}

void BufferIterator::start()
{
	this->flag = 0;
}

void BufferIterator::next()
{
	if (this->finish() == true) {
		throw "You are out of border";
	}
	this->flag++;
}

bool BufferIterator::finish()
{
	if (this->flag >= queue->getSize()) {
		return true;
	}
	return false;
}

int BufferIterator::getValue()
{
	return queue->top();
}

BufferIterator::~BufferIterator()
{
}
