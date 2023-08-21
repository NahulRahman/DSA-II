#include <iostream>
using namespace std;

/*Algorithm:

Choose a pivot element.
Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
Recursively apply Quick Sort to the sub-arrays.
Combine the sorted sub-arrays.*/

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n = 10; // Number of elements in the array
    int arr[] = { 10, 7, 8, 9, 1, 5, 4, 6, 6 }; // Initialize the array

    quickSort(arr, 0, n - 1);

    cout << "Sorted array using Quick Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
