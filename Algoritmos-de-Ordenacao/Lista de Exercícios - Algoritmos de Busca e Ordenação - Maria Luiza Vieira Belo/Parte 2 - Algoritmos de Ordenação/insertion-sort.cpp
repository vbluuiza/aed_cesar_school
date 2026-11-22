#include <iostream>
#include <vector>
using namespace std;

// 1.
void insertionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp) {
           arr[j + 1] = arr[j];
           j--;
        }
        arr[j + 1] = temp;
    }
}

// 2.
void insertionSortPares(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            int temp = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] % 2 == 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}

// 3.
void insertionSortDecrescente(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < temp) {
           arr[j + 1] = arr[j];
           j--;
        }
        arr[j + 1] = temp;
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
    vector<int> arr1 = {22, 11, 99, 88, 9, 7, 42, 65, 33, 10};
    printArr(arr1);
    insertionSort(arr1);
    printArr(arr1);

    // 2.
    vector<int> arr2 = {9, 8, 3, 4, 7, 6, 1, 2, 5, 0};
    printArr(arr2);
    insertionSortPares(arr2);
    printArr(arr2);

    // 3. 
    vector<int> arr3 = {30, 20, 10, 40, 50, 70, 60, 90, 80, 100};
    printArr(arr3);
    insertionSortDecrescente(arr3);
    printArr(arr3);
    return 0;
}