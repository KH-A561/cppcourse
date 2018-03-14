#include "stdafx.h"
#include "CircularBuffer.h"


CircularBuffer::CircularBuffer()
{
	this->data = new DynamicArrayInt();
	this->head = 0;
	this->tail = 0;
	this->size = 0;
}

CircularBuffer::CircularBuffer(int& size)
{
	this->data = new DynamicArrayInt(size);
	this->head = 0;
	this->tail = 0;
	this->size = 0;
}

void CircularBuffer::push(int& element)
{
	if (tail == getSize() - 1) {
		if (size != 0) {
			throw "Your array is full";
		}
		this->data[tail] = element;
		tail == 0;
		size++;
	}
	if (tail == head && size != 0) {
		throw "Your array is full";
	}
	this->data[tail] = element;
	tail++;
	size++;
}

int CircularBuffer::getSize()
{
	return this->size;
}

int CircularBuffer::pull()
{
	int buf = (*data)[head];
	head++;
	size--;
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
	return this->size == 0;
}


CircularBuffer::~CircularBuffer()
{
	delete data;
}
