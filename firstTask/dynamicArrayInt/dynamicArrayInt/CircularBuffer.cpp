#include "stdafx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer()
{
	this->data = new DynamicArrayInt();
	this->head = 0;
	this->tail = 0;
}

CircularBuffer::CircularBuffer(int& size)
{
	this->data = new DynamicArrayInt(size);
	this->head = 0;
	this->tail = 0;
}

void CircularBuffer::push(int& element)
{
	if (tail >= this->getSize) {
		throw "Your buffer is full!";
	}
	this->data[tail] = element;
	tail++;
}

int CircularBuffer::getSize()
{
	return tail - head + 1;
}

int CircularBuffer::pull()
{
	int buf = (*data)[head];
	head++;
	if (head > tail) {
		head = tail;
	}
	return buf;
}

int CircularBuffer::top()
{
	return (*data)[head];
}

void CircularBuffer::makeEmpty()
{
	delete[] this->data;
	head = 0;
	tail = 0;
}

bool CircularBuffer::isEmpty()
{
	return this->head == this->tail;
}


CircularBuffer::~CircularBuffer()
{
	delete data;
}
