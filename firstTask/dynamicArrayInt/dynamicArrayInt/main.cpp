// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DynamicArrayInt.h"
#include "CircularBuffer.h"
#include "BufferIterator.h"
#include <iostream>
#include <stdexcept>



int main()
{
	DynamicArrayInt arrayFive (5, 5);
	DynamicArrayInt arrayThree(3, 3);
	DynamicArrayInt arrayConcat;
	std::cout << arrayFive;
	arrayConcat = arrayFive + arrayThree;
	std::cout << arrayConcat;
	arrayConcat.resize(10);
	std::cout << arrayConcat;
	arrayConcat = arrayThree;
	std::cout << arrayConcat;
	try {
		std::cout << "\n" << (arrayConcat == arrayThree);
		std::cout << "\n" << (arrayConcat == arrayFive);
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	try {
		std::cout << "\n" << (arrayConcat != arrayThree);
		std::cout << "\n" << (arrayConcat != arrayFive);
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	std::cout << "\n" << (arrayConcat == arrayThree);
	std::cout << "\n" << (arrayConcat > arrayFive);
	std::cout << "\n" << (arrayConcat < arrayThree);
	std::cout << "\n" << (arrayConcat >= arrayThree);
	DynamicArrayInt arrayIn;
	std::cin >> arrayIn;
	std::cout << arrayIn;
	CircularBuffer queue(3);
	try {
		queue.push(0);
		queue.push(1);
		queue.push(2);
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	std::cout << "\n" << queue.getLength();
	int buf = queue.pull();
	std::cout << "\n" << buf;
	std::cout << "\n" << queue.getLength();
	try {
		queue.push(3);
		buf = queue.top();
		std::cout << "\n" << buf;
		std::cout << "\n" << queue.getLength();
	}
	catch (std::invalid_argument e) {
		std::cerr << "\n" << e.what();
	}
	getchar();
	return 0;
}

