#include "stdafx.h"
#include "CircularBuffer.h"
#include "DynamicArrayInt.h"


CircularBuffer::CircularBuffer()
{
	this->data = new DynamicArrayInt();
	this->head = 0;
	this->tail = 0;
	this->length = 0;
}

CircularBuffer::CircularBuffer(int size)
{
	this->data = new DynamicArrayInt(size);
	this->head = 0;
	this->tail = 0;
	this->length = 0;
}

void CircularBuffer::push(int element)
{
	if (getLength() == data->length()) {
		throw "Your array is full";
	}
	(*data)[tail] = element;
	if (tail == data->length() - 1) {
		tail = 0;
	} else {
		tail++;
	}
	length++;
}

int CircularBuffer::getLength()
{
	return this->length;
}

int CircularBuffer::pull()
{
	int buf = (*data)[head];
	head++;
	length--;
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
	return this->getLength() == 0;
}


CircularBuffer::~CircularBuffer()
{
	data->~DynamicArrayInt();
}
