#include "stdafx.h"
#include <stdexcept>
#include <stdio.h>
#include "DoublyLinkedCircularList.h"
#include <stdlib.h> 
#include <cstdlib> 

template<typename T>
DoublyLinkedCircularList<T>::node::node(T elem, node* prev, node* nxt) : data(elem), previous(prev), next(nxt) {}

template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList()
{
	size = 0;
	head = new node(nullptr, head, head);
	current = nullptr;
}

template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList(T& data)
{
	size = 1;
	head = new node(data, head, head);
	current = nullptr;
}

/*template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList(const DoublyLinkedCircularList<T> &copy)
{


}*/

template<typename T>
void DoublyLinkedCircularList<T>::push(T& elem)
{
	if (current == nullptr) throw std::invalid_argument("There's no iterator for this list");
	node* newElem = new node(elem, current, current->next);
	current->next->previous = newElem;
	current->next = newElem;
	current = current->previous;
	size++;
}

template<typename T>
void DoublyLinkedCircularList<T>::remove()
{
	this->current->next->previous = this->current->previous;
	this->current->previous->next = this->current->next;
	this->current->~node();
	size--;
}

template<typename T>
IIterator<T>* DoublyLinkedCircularList<T>::listIterator(T elem)
{
	IIterator<T>* iter = this->iterator();
	iter->start();
	while (iter->hasNext()) {
		if (iter->get() == elem) {
			return iter;
		}
		else {
			iter->next();
		}
	}
	return nullptr;
}

template<typename T>
void DoublyLinkedCircularList<T>::clear()
{
	IIterator<T>* iter = this->iterator();
	iter->start();
	while (iter->hasNext()) {
		this->remove();
		iter->next();
	}
}

template<typename T>
bool DoublyLinkedCircularList<T>::isEmpty()
{
	return this->size == 0;
}

template<typename T>
int DoublyLinkedCircularList<T>::getSize()
{
	return this->size;
}

template<typename T>
IIterator<T>* DoublyLinkedCircularList<T>::iterator()
{
	IIterator<T>* iter = new Iterator(*this);
	iter->start();
	return iter;
}

template<typename T>
DoublyLinkedCircularList<T>::~DoublyLinkedCircularList()
{
	clear();
	size = 0;
	delete head;
	current = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
DoublyLinkedCircularList<T>::Iterator::Iterator(DoublyLinkedCircularList<T>& list)
{
	this->list = &list;
}

template<typename T>
void DoublyLinkedCircularList<T>::Iterator::start()
{
	this->list->current = this->list->head;
}

template<typename T>
T DoublyLinkedCircularList<T>::Iterator::get()
{
	return this->list->current->data;
}

template<typename T>
void DoublyLinkedCircularList<T>::Iterator::next()
{
	this->list->current = this->list->current->next;
}

template<typename T>
bool DoublyLinkedCircularList<T>::Iterator::hasNext()
{
	return (this->list->current == this->list->head->previous) ? false : true;
}

template<typename T>
DoublyLinkedCircularList<T>::Iterator::~Iterator()
{
	this->list->current = nullptr;
	this->list = nullptr;
}

