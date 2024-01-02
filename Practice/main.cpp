#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <cmath>

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

    //merge sort
    static void merge(std::vector<int>& arr, int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        std::vector<int> leftArr(n1);
        std::vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[middle + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            }
            else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    static void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;
            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }

};

//with memoization
int fibonacci(int n, std::map<int, int>& mem) {
    if (mem.find(n) != mem.end()) {
        return mem[n];
    }
    if (n <= 2) {
        return 1;
    }
    int calc = fibonacci(n - 1, mem) + fibonacci(n - 2, mem);
    mem[n] = calc;
    return calc;
}

int lcs(std::string X, std::string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return std::max(lcs(X, Y, m, n - 1),
            lcs(X, Y, m - 1, n));
}

int main() {
    std::map<int, int> aMap;
    std::cout << fibonacci(70, aMap);
}

