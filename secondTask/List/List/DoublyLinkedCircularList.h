#pragma once
#include "IList.h"

template<typename T>
class DoublyLinkedCircularList :
			public IList<T>
{
private:
	struct node
	{
		T data;
		node* previous;
		node* next;

		node(T data = T(), node* next = nullptr, node* previous = nullptr);
	/*		this->data = data;
			this->previous = previous;
			this->next = next;
		}
		*/
	};
	node* head;
	node* current;
	int size;

public:
	class Iterator : public IIterator<T> {
		DoublyLinkedCircularList<T>* list;
	public:
		Iterator(DoublyLinkedCircularList& list);
		virtual ~Iterator();
		virtual void start();
		virtual T get();
		virtual void next();
		virtual bool hasNext();
	};

	DoublyLinkedCircularList();
	DoublyLinkedCircularList(T& data);
	DoublyLinkedCircularList(DoublyLinkedCircularList<T> &copy);
	DoublyLinkedCircularList(DoublyLinkedCircularList<T> &&stolen);
	DoublyLinkedCircularList& operator= (DoublyLinkedCircularList& copy);
	DoublyLinkedCircularList& operator= (DoublyLinkedCircularList&& stolen);
	virtual ~DoublyLinkedCircularList();

	virtual void push(T& elem);
	virtual void remove();
	virtual IIterator<T>* listIterator(T elem);
	virtual void clear();
	virtual bool isEmpty();
	virtual int getSize();
	virtual IIterator<T>* iterator();
	virtual void toString();
};
