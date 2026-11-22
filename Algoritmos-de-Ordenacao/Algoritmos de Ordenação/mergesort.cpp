#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    int leftArr[sizeLeft];
    int rightArr[sizeRight];
    for (int i = 0; i < sizeLeft; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < sizeRight; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < sizeLeft) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < sizeRight) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {3, 7, 8, 5, 4, 2, 6, 1};
    cout << "Antes de ordenar (MergeSort): " <<endl;
    for(int x: arr) { cout << x << " "; }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);
    cout << "Depois de ordernar (MergeSort): " <<endl;
    for(int x : arr) { cout << x << " "; }
    cout << endl;

    return 0;
}