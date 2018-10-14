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
  class Iterator {
   private:
    LinkedHashEntry **arrayOfKeys;
    int current;
    int length;

   public:
    Iterator(HashTable<K,V> &hashTable) {
      length = hashTable.length;
      arrayOfKeys = new LinkedHashEntry*[hashTable.length];
      int j = 0;
      for (int i = 0; i < TABLE_SIZE, j < hashTable.length; i++) {
        if (hashTable.array[i]) {
          arrayOfKeys[j] = hashTable.array[i];
          j++;
        }
      }
      current = 0;
    };
    V next() {
      V result = arrayOfKeys[current]->value;
      current++;
      return result;
    };
    bool hasNext() {
      return current != length;
    };
    ~Iterator() {
      delete[] arrayOfKeys;
    };
  };

  HashTable();
  ~HashTable();
  void insert(K key, V value);
  V get(K key);
  void remove(K key);
  void removeAll();
  int getLength();
  bool isEmpty();
  Iterator& iterator();
};

#endif //HASH_TABLE_HASHTABLE_H

