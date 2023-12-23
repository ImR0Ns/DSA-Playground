#include <iostream>
#include <vector>


//I DID NOT KNOW HOW TO SEPARATE THIS, STILL LOOKING FOR TO DO IT CORRECTLY

//I tried to do this in the stack because it is faster than in the heap

template <class T, class T2>
struct HTItems {
	T key;
	T2 value;
	HTItems() : key(NULL), value(NULL) {};
	HTItems(T key, T2 value) : key(key), value(value) {};
};

template <class T, class T2>
struct HTable {
	static int const maxSize = 10; // Limit in table is 10
	HTItems<T, T2> array[maxSize];

	int hashFunction(T key) {
		return key % maxSize;
	}

	void addItem(T key, T2 value) {
		int theHash = hashFunction(key);

		while (array[theHash].key) {
			theHash = (theHash + 1) % maxSize;
		}

		array[theHash] = HTItems<T, T2>(key, value);
	}


	//get value by key
	T2 getValueByKey(T key) {
		//hash for check
		int theHash = hashFunction(key);
		//check if exists
		if (array[theHash].key != NULL) {
			return array[theHash].value;
		}
		else {
			std::cout << "The key has no value";
			//return -1 no value
			return -1;
		}
	}

	T2& operator[](T key) { // & - to modify not to create a clone of that!
		int theHash = hashFunction(key);

		while (array[theHash].key != 0 && array[theHash].key != key) {
			theHash = (theHash + 1) % maxSize;
		}

		if (array[theHash].key == 0) {
			addItem(key, 0);
		}

		return array[theHash].value;
	}

	//return max size
	int max_size() const {
		return maxSize;
	}

	int size() const {
		int counter = 0;
		for (int i = 0; i < maxSize; i++) {
			if (array[i].key) {
				counter++;
			}
		}
		return counter;
	}

	void clear(T key) {
		int theHash = hashFunction(key);

		if (array[theHash].key) {
			array[theHash].key = NULL;
			array[theHash].value = NULL;
		}
		else {
			std::cout << "No element to delete with that key!\n";
		}
	}

};


