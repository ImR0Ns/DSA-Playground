#include <iostream>
#include <vector>
#include <array>

class SearchAndSort {
public:
    //SEARCH
    // 
    //liniar is by default O(n) | one iteration
    //binary search
    static int binarySearch(std::vector<int> arr, int start, int finish, int value) {
        int middle = (start + finish) / 2;
        if (arr[middle] == value) {
            return middle;
        }
        else if (arr[middle] < value) {
            return binarySearch(arr, middle, finish, value);
        }
        else {
            return binarySearch(arr, start, middle, value);
        }


        return 0;
    };
    //hash I did on Hash Table
    //SORT
    template<int size>
    static void bubbleSort(std::array<int, size>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] > arr[j]) { // if we change the sign to < it will descending sort
                    int temp = arr[i]; //temp value
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    template<int size>
    static void selectSort(std::array<int, size>& arr) {
        for (int i = 0; i < arr.size(); i++) {

            int currentValue = arr[i];
            std::array<int, 2> minValue = { arr[i], i }; //get the min value

            //find the min value 
            for (int j = i + 1; j < arr.size(); j++) {
                if (minValue[0] > arr[j]) {
                    minValue[0] = arr[j];
                    minValue[1] = j;
                }
            }

            //swap
            arr[i] = minValue[0];
            arr[minValue[1]] = currentValue;


        }
    }

    template<int size>
    static void insertionSort(std::array<int, size>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int key = arr[i];
            int j = i - 1;

            while (j>=0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    std::array<int, 5> arr = { 12, 11, 13, 5, 6 }; //11, 12, 5, 13
    SearchAndSort::insertionSort(arr);
    for (int x : arr) {
        std::cout << x << "\n";
    }
}

