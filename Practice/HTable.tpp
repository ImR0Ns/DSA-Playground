#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP

template <class T, class T2>
void HTable<T, T2>::addItem(T key, T2 value) {
    int theHash = hashFunction(key);

    while (array[theHash].key) {
        theHash = (theHash + 1) % maxSize;
    }

    array[theHash] = HTItems<T, T2>(key, value);
}

template <class T, class T2>
T2 HTable<T, T2>::getValueByKey(T key) {
    int theHash = hashFunction(key);

    if (array[theHash].key != T()) {
        return array[theHash].value;
    }
    else {
        std::cout << "The key has no value" << std::endl;
        return T2();
    }
}

template <class T, class T2>
T2& HTable<T, T2>::operator[](T key) {
    int theHash = hashFunction(key);

    while (array[theHash].key != T() && array[theHash].key != key) {
        theHash = (theHash + 1) % maxSize;
    }

    if (array[theHash].key == T()) {
        addItem(key, T2());
    }

    return array[theHash].value;
}

template <class T, class T2>
int HTable<T, T2>::max_size() const {
    return maxSize;
}

template <class T, class T2>
int HTable<T, T2>::size() const {
    int counter = 0;
    for (int i = 0; i < maxSize; i++) {
        if (array[i].key) {
            counter++;
        }
    }
    return counter;
}

template <class T, class T2>
void HTable<T, T2>::clear(T key) {
    int theHash = hashFunction(key);

    if (array[theHash].key != T()) {
        array[theHash].key = T();
        array[theHash].value = T2();
    }
    else {
        std::cout << "No element to delete with that key!" << std::endl;
    }
}

template <class T, class T2>
void HTable<T, T2>::printMap() {
    for (int i = 0; i < maxSize; i++) {
        if (array[i].key) {
            std::cout << array[i].key << " " << array[i].value << std::endl;
        }
    }
}

#endif  // HASHTABLE_TPP
