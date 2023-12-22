#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

template <class T, class T2>
struct HTItems {
    T key;
    T2 value;

    HTItems() : key(T()), value(T2()) {};
    HTItems(T k, T2 v) : key(k), value(v) {};
};

template <class T, class T2>
class HTable {
private:
    static const int maxSize = 10; // Limit in the table is 10
    HTItems<T, T2> array[maxSize];

    int hashFunction(T key) {
        return key % maxSize; // Find the location in the array
    }

public:
    void addItem(T key, T2 value);
    T2 getValueByKey(T key);
    T2& operator[](T key);
    int max_size() const;
    int size() const;
    void clear(T key);
    void printMap();
};

// Implementation of template member functions
#include "HTable.tpp"

#endif  // HASHTABLE_H
