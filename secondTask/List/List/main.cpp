// List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "IList.h"
#include "DoublyLinkedCircularList.h"
#include "DoublyLinkedCircularList.cpp"

int main()
{
	char symbol = 'a';
	DoublyLinkedCircularList<char> list;
	std::cout << list.getSize() << std::endl;
	try {
		list.push(symbol);
		symbol = 'b';
		list.push(symbol);
		symbol = 'c';
		list.push(symbol);
		list.push(symbol);
		std::cout << list.getSize() << std::endl;
		list.remove();
		std::cout << list.getSize() << std::endl;
		list.toString(); // 'abc' size: 3

		symbol = 'b';
		IIterator<char>* iter = list.listIterator(symbol);
		symbol = 'd';
		list.push(symbol);
		list.toString(); // 'abdc' size: 4

		list.clear();
		std::cout << list.getSize() << std::endl; // ' ', size: 0
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what();
	}
	_getch();
    return 0;
}

