//
// Created by alexander on 27.08.18.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include<bits/stdc++.h>

const int TABLE_SIZE = 128;

template<typename K, typename V>
class HashTable {
 private:
//  template<typename K, typename V>
  struct LinkedHashEntry {
   public:
    K key;
    V value;
    LinkedHashEntry(K key, V value) {
      this->key = key;
      this->value = value;
    }

    K getKey() {
      return key;
    }

    V getValue() {
      return value;
    }

    void setValue(V value) {
      this->value = value;
    }
  };
  LinkedHashEntry **array;
  int length;
  static int hashCode(K key);

 public:
  HashTable();
  ~HashTable();
  void insert(K key, V value);
  V get(K key);
  void remove(K key);
  void removeAll();
  int getLength();
  bool isEmpty();
};

#endif //HASH_TABLE_HASHTABLE_H

