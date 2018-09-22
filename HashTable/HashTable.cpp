//
// Created by alexander on 09.09.18.
//

#include "HashTable.h"

template<typename K, typename V>
HashTable<K, V>::HashTable() {
  array = new LinkedHashEntry *[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) {
    array[i] = nullptr;
  }
  length = 0;
}

template<typename K, typename V>
int HashTable<K, V>::hashCode(K key) {
  return key % TABLE_SIZE;
}

template<typename K, typename V>
void HashTable<K, V>::insert(K key, V value) {
  int hashCode = HashTable::hashCode(key);
  while (array[hashCode] != nullptr && array[hashCode]->getKey() != key) {
    hashCode = HashTable::hashCode(hashCode + 1);
  }
  if (array[hashCode] != nullptr) {
    array[hashCode]->value = value;
  } else {
    array[hashCode] = new LinkedHashEntry(key, value);
    length++;
  }
}

template<typename K, typename V>
V HashTable<K, V>::get(K key) {
  int hashCode = HashTable::hashCode(key);
  while (array[hashCode] != nullptr && array[hashCode]->getKey() != key) {
    hashCode = HashTable::hashCode(hashCode + 1);
  }
  if (array[hashCode] != nullptr) {
    return array[hashCode]->value;
  } else {
    throw std::invalid_argument("Element is not found");
  }
}

template<typename K, typename V>
int HashTable<K, V>::getLength() {
  return length;
}

template<typename K, typename V>
bool HashTable<K, V>::isEmpty() {
  return length == 0;
}

template<typename K, typename V>
void HashTable<K, V>::remove(K key) {
  int hashCode = HashTable::hashCode(key);
  while (array[hashCode] != nullptr && array[hashCode]->getKey() != key) {
    hashCode = HashTable::hashCode(hashCode + 1);
  }
  if (array[hashCode] != nullptr) {
    array[hashCode] = nullptr;
    length--;
  } else {
    throw std::invalid_argument("Element is not found");
  }
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
  delete[]array;
  length = 0;
}

template<typename K, typename V>
void HashTable<K, V>::removeAll() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    array[i] = nullptr;
  }
  length = 0;
}


