#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Take the pivot as the lower bound
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    int pivotIndex = partition(arr, low, high);
    if (pivotIndex == k - 1) {
        return arr[pivotIndex];
    } else if (pivotIndex < k - 1) {
        return quickSelect(arr, pivotIndex + 1, high, k);
    } else {
        return quickSelect(arr, low, pivotIndex - 1, k);
    }
}

int findKthLargest(int nums[], int length, int k) {
    if (k >= 1 && k <= length) {
        return quickSelect(nums, 0, length - 1, k);
    } else {
        return -1; // Return a default value if k is out of bounds
    }
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int nums[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter k: ";
    cin >> k;

    int kthLargest = findKthLargest(nums, n, k);

    if (kthLargest != -1) {
        cout << "The " << k << "th largest element is: " << kthLargest << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}




/*
#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Take the pivot as the lower bound
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    int pivotIndex = partition(arr, low, high);
    if (pivotIndex == k - 1) {
        return arr[pivotIndex];
    } else if (pivotIndex < k - 1) {
        return quickSelect(arr, pivotIndex + 1, high, k);
    } else {
        return quickSelect(arr, low, pivotIndex - 1, k);
    }
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int length = sizeof(nums) / sizeof(nums[0]);
    int kthLargest = quickSelect(nums, 0, length - 1, k);

    if (kthLargest != -1) {
        cout << "The " << k << "th largest element is: " << kthLargest << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}
*/
