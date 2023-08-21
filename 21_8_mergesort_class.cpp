#include <iostream>
#include <algorithm>
using namespace std;

int b[100];

void merge(int a[], int low, int middle, int high) {
    int i = low;
    int j = middle + 1;
    int k = low;

    while (i <= middle && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            k++;
            i++;
        } else {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= middle) {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high) {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int p = low; p <= high; p++) {
        a[p] = b[p];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergeSort(a, low, middle);
        mergeSort(a, middle + 1, high);
        merge(a, low, middle, high);
    }
}

int main() {
    int n = 6; // Number of elements in the array
    int a[] = { 12, 11, 13, 5, 6, 7 }; // Initialize the array

    mergeSort(a, 0, n - 1);

    cout << "Sorted array using Merge Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

/*
#include <iostream>
#include<algorithm>
using namespace std;
int b[100];
void merge(int a[], int low, int middle, int high) {
    int i = low;
    int j = middle+1;
    int k = low;

    while(i<=middle&&j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>middle){
        while(j<high){
            b[k]=a[j];
            k++;
            j++;
        }
    }else{
            b[k]=a[i];
            k++;
            i++;
        }

    for (int p = 0; p < 6; p++) {
        a[p] = b[p];
    }


}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int middle = (low+high) / 2;
        mergeSort(a, low, middle);
        mergeSort(a, middle + 1, high);
        merge(a, low, middle, high);

    }
}

int main() {
    int n = 6; // Number of elements in the array
    int a[] = { 12, 11, 13, 5, 6, 7 }; // Initialize the array

    mergeSort(a, 0, n - 1);

    cout << "Sorted array using Merge Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}
*/
