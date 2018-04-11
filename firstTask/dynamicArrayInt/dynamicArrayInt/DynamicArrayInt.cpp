#include "stdafx.h"
#include "DynamicArrayInt.h"
#include <stdexcept>
#include <stdio.h>

#define PRINTER(Variable) (#Variable)


DynamicArrayInt::DynamicArrayInt()
{
	size = 0;
	array = new int[0];
}

DynamicArrayInt::DynamicArrayInt(int size)
{
	this->size = size;
	array = new int[size];
}

DynamicArrayInt::DynamicArrayInt(int size, int n)
{
	this->size = size;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = n;
	}
}

DynamicArrayInt::DynamicArrayInt(DynamicArrayInt &arrayCopy)
{
	size = arrayCopy.size;
	array = new int[arrayCopy.size];
	for (int i = 0; i < arrayCopy.size; i++)
	{
		array[i] = arrayCopy.array[i];
	}
}

DynamicArrayInt::DynamicArrayInt(DynamicArrayInt &&arrayTransfer)
{
	size = arrayTransfer.size;
	array = arrayTransfer.array;
	arrayTransfer.size = NULL;
	arrayTransfer.array = nullptr;
}

DynamicArrayInt::~DynamicArrayInt()
{
	delete[] array;
}

int DynamicArrayInt::length()
{
	return size;
}

int & DynamicArrayInt::operator[](int i)
{
	if (i >= 0 && i < size) {
		return DynamicArrayInt::array[i];
	}
	throw -1;
}

void DynamicArrayInt::resize(int newSize)
{
	int *newArray = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		newArray[i] = array[i];
	}
	if (newSize > this->size) {
		for (int i = this->size; i < newSize; i++)
		{
			newArray[i] = 0;
		}
	}
	delete[] array;
	array = newArray;
	this->size = newSize;
}

DynamicArrayInt& DynamicArrayInt::operator=(const DynamicArrayInt& secondArr)
{
	delete[] array;
	this->size = secondArr.size;
	array = new int[secondArr.size];
	for (int i = 0; i < secondArr.size; i++) {
		array[i] = secondArr.array[i];
	}
	return *this;
}

DynamicArrayInt & DynamicArrayInt::operator=(DynamicArrayInt && secondArr)
{
	if (this != &secondArr) {
		delete[] this->array;
		this->size = secondArr.size;
		this->array = secondArr.array;
		secondArr.size = 0;
		secondArr.array = nullptr;
	}
	return *this;
}

const bool operator==(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr.size != secondArr.size) {
		throw std::invalid_argument("Array lengths are unequal");
	}
	for (int i = 0; i < secondArr.size; i++) {
		if (firstArr.array[i] != secondArr.array[i]) { return false; }
	}
	return true;
}

const bool operator!=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr.size != secondArr.size) {
		throw std::invalid_argument("Array lengths are unequal");
	}
	for (int i = 0; i < secondArr.size; i++) {
		if (firstArr.array[i] == secondArr.array[i]) { return false; }
	}
	return true;
}

const bool operator<(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	try {
		if (firstArr == secondArr) return false;
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return true; }
		if (firstArr.array[i] > secondArr.array[i]) { return false; }
	}
	if (firstArr.size < secondArr.size) { return true; }
	return false;
}

const bool operator>(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	try {
		if (firstArr == secondArr) return false;
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return false; }
		if (firstArr.array[i] > secondArr.array[i]) { return true; }
	}
	if (firstArr.size > secondArr.size) { return true; }
	return false;
}

const bool operator<=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	try {
		if (firstArr == secondArr) return true;
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return true; }
		if (firstArr.array[i] > secondArr.array[i]) { return false; }
	}
	if (firstArr.size <= secondArr.size) { return true; }
	return false;
}

const bool operator>=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	try {
		if (firstArr == secondArr) return true;
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return false; }
		if (firstArr.array[i] > secondArr.array[i]) { return true; }
	}
	if (firstArr.size >= secondArr.size) { return true; }
	return false;
}

    DynamicArrayInt& operator+(DynamicArrayInt& firstArr, DynamicArrayInt& secondArr)
{
	DynamicArrayInt* newArr = new DynamicArrayInt(firstArr.size + secondArr.size);
	newArr->size = firstArr.size + secondArr.size;
	for (int i = 0; i < firstArr.size; i++) {
		newArr->array[i] = firstArr.array[i];
	}
	for (int i = 0; i < secondArr.size; i++) {
		newArr->array[firstArr.size + i] = secondArr.array[i];
	}
	return *newArr;
}

std::istream & operator>> (std::istream & inStream, DynamicArrayInt & inArr)
{
	std::cout << "Enter a size of the array: ";
	std::cin >> inArr.size;
	std::cout << "\n";	
	inArr.array = new int[inArr.size];
	for (int i = 0; i < inArr.size; i++)
	{
		std::cout << "Enter an element of the array: ";
		std::cin >> inArr.array[i];
		std::cout << "\n";
	}
	std::cout << std::endl;
	return inStream;
}



std::ostream & operator<< (std::ostream & outStream, const DynamicArrayInt & outArr)
{
	outStream << " [";
	for (int i = 0; i < outArr.size - 1; i++)
	{
		outStream << outArr.array[i] << ", ";
	}
	outStream << outArr.array[outArr.size - 1] << "]" << std::endl;
	return outStream;
}
