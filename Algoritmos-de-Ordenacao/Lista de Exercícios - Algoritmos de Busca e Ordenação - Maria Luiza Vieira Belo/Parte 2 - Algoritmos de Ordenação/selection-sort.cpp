#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1.
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_index = i;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// 2.
void selectionSortContarTrocas(vector<int>& arr) {
    int trocas = 0;
    for (int i = 0; i < arr.size() -1; i++) {
        int min_index = i;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
            trocas++;
        }
    }
    cout << "Quantidade de trocas feitas: " << trocas << endl;
}

// 3.
void selectionSortDecrescente(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_index = i;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
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
    vector<int> arr1 = {29, 10, 14, 37, 13, 40, 2, 7, 5, 18};
    printArr(arr1);
    selectionSort(arr1);
    printArr(arr1);
    
    // 2.
    vector<int> arr2 = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    printArr(arr2);
    selectionSortContarTrocas(arr2);
    printArr(arr2);

    // 3. 
    vector<int> arr3 = {42, 33, 60, 15, 75, 12, 25, 90, 1, 6};
    printArr(arr3);
    selectionSortDecrescente(arr3);
    printArr(arr3);
    return 0;
}