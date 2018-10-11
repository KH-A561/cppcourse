//
// Created by alexander on 11.10.18.
//

#include "DoublyLinkedCircularList.h"

template<typename T>
DoublyLinkedCircularList<T>::node::node(T elem, node *nxt, node *prev) : data(elem), next(nxt), previous(prev) {}

template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList() {
  size = 0;
  head = new node(NULL, head, head);
  current = head;
}

template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList(DoublyLinkedCircularList<T> &copy) {
  head = new node(nullptr, head, head);
  node *temp = copy.head->next;
  current = head;
  size = 0;
  while (temp != copy.head) {
    auto *buf = new node(temp->data, head, current);
    current->next = buf;
    current = current->next;
    head->previous = buf;
    temp = temp->next;
    size++;
  }
}

template<typename T>
DoublyLinkedCircularList<T>::DoublyLinkedCircularList(DoublyLinkedCircularList<T> &&stolen) {
  this->head = stolen.head;
  this->current = stolen.current;
  this->size = stolen.size;
  stolen.head = nullptr;
  stolen.current = nullptr;
  stolen.size = 0;
}

template<typename T>
DoublyLinkedCircularList<T> &DoublyLinkedCircularList<T>::operator=(DoublyLinkedCircularList<T> const &copy) {
  if (this == &copy) {
    return *this;
  }
  clear();
  current = head;
  node *temp = copy.head->next;
  while (temp != copy.head) {
    current->next = new node(temp->data, head, current);
    current = current->next;
    head->previous = current;
    temp = temp->next;
  }
  size = copy.size;
  return *this;
}

template<typename T>
DoublyLinkedCircularList<T> &DoublyLinkedCircularList<T>::operator=(DoublyLinkedCircularList<T> &&stolen) {
  if (this != &stolen) {
    this->head = stolen.head;
    this->current = stolen.current;
    this->size = stolen.size;
    stolen.head = nullptr;
    stolen.current = nullptr;
    stolen.size = 0;
  }
  return *this;
}

template<typename T>
void DoublyLinkedCircularList<T>::push(T &elem) {
  if (size != 0) {
    auto *newElem = new node(elem, current, current->previous);
    current->previous->next = newElem;
    current->previous = newElem;
    current = current->previous;
    size++;
  } else {
    auto *newElem = new node(elem, head, head);
    head->next = newElem;
    head->previous = newElem;
    current = head->next;
    size++;
  }
}

template<typename T>
void DoublyLinkedCircularList<T>::remove() {
  if (current == head) {
    current = head->next;
  }
  if (size == 0) {
    throw std::invalid_argument("An exception at pop(): list is empty");
  }
  if (size == 1) {
    delete current;
    head->next = head;
    head->previous = head;
    size--;
  } else {
    current->previous->next = current->next;
    current->next->previous = current->previous;
    node *temp = current;
    current = current->next;
    temp->next = nullptr;
    temp->previous = nullptr;
    delete temp;
    size--;
  }
}

template<typename T>
IIterator<T> *DoublyLinkedCircularList<T>::listIterator(T elem) {
  IIterator<T> *iter = this->iterator();
  iter->start();
  while (!(iter->hasNext())) {
    if (iter->get() == elem) {
      return iter;
    }
    iter->next();
  }
  throw std::invalid_argument("Element not found");
  return nullptr;
}

template<typename T>
void DoublyLinkedCircularList<T>::clear() {
  if (head == nullptr) {
    return;
  }
  current = head->next;
  while (!isEmpty()) {
    remove();
  }
}

template<typename T>
bool DoublyLinkedCircularList<T>::isEmpty() {
  return this->size == 0;
}

template<typename T>
int DoublyLinkedCircularList<T>::getSize() {
  return this->size;
}

template<typename T>
IIterator<T> *DoublyLinkedCircularList<T>::iterator() {
  IIterator<T> *iter = new Iterator(*this);
  iter->start();
  return iter;
}

template<typename T>
void DoublyLinkedCircularList<T>::toString() {
  IIterator<T> *iter = this->iterator();
  while (!(iter->hasNext())) {
    std::cout << iter->get();
    iter->next();
  }
  std::cout << std::endl;
}

template<typename T>
DoublyLinkedCircularList<T>::~DoublyLinkedCircularList() {
  clear();
  size = 0;
  delete head;
  current = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
DoublyLinkedCircularList<T>::Iterator::Iterator(DoublyLinkedCircularList<T> &list) {
  this->list = &list;
}

template<typename T>
void DoublyLinkedCircularList<T>::Iterator::start() {
  this->list->current = this->list->head->previous;
}

template<typename T>
T DoublyLinkedCircularList<T>::Iterator::get() {
  return this->list->current->data;
}

template<typename T>
void DoublyLinkedCircularList<T>::Iterator::next() {
  this->list->current = this->list->current->previous;
}

template<typename T>
bool DoublyLinkedCircularList<T>::Iterator::hasNext() {
  return list->current == list->head;
}

template<typename T>
DoublyLinkedCircularList<T>::Iterator::~Iterator() {
  this->list->current = nullptr;
  this->list = nullptr;
}