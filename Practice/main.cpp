#include <iostream>
#include <vector>

//I tried to do this in the stack because it is faster than in the heap

struct HTItems {
	char key;
	int value;
	HTItems() : key(NULL), value(NULL) {};
	HTItems(char key, int value) : key(key), value(value) {};
};

struct HTable {
	static int const maxSize = 10;
	HTItems array[maxSize];

	int hashFunction(char key) {
		return key % maxSize;
	}

	void addItem(char key, int value) {
		int theHash = hashFunction(key);

		while (array[theHash].key) {
			theHash = (theHash + 1) % maxSize;
		}

		array[theHash] = HTItems(key, value);
	}


	//get value by key
	int getValueByKey(char key) {
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

	int& operator[](char key) { // & - to modify not to create a clone of that!
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

	void clear(char key) {
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

int main() {
	HTable table;

	table['A'] = 1;
	table['K'] = 3;
	table['a'] = 1;

	//table.clear('e');

	for (int i = 0; i < table.maxSize; i++) {
		if (table.array[i].key) {
			std::cout << table.array[i].key << " " << table.array[i].value << std::endl;
		}
	}
}
