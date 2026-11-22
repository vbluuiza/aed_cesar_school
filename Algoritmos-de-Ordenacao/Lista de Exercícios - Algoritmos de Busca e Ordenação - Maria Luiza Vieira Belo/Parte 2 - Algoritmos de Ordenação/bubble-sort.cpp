#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1.
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2.
void bubbleSortOtimizado(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            cout << "Nenhuma troca feita. Vetor já está ordenado." << endl;
            break;
        }
    }
}


// 3.
void bubbleSortDecrescente(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ",  ";
    }
    cout << endl;
}
int main() {
    // 1.
    vector<int> arr1 = {9, 7, 5, 3, 1, 2, 4, 6, 8, 0};
    printArr(arr1);
    bubbleSort(arr1);
    printArr(arr1);

    // 2.
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArr(arr2);
    bubbleSortOtimizado(arr2);
    printArr(arr2);

    // 3. 
    vector<int> arr3 = {30, 20, 10, 40, 50, 70, 60, 90, 80, 100};
    printArr(arr3);
    bubbleSortDecrescente(arr3);
    printArr(arr3);
    return 0;
}