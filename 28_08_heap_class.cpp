///Max Heap

#include<bits/stdc++.h>
using namespace std;

class Heap {
private:
    int a[101], size;

public:
    Heap() {
        size = 0;
    }

private:
    void bottomTopAdjust(int i) {
        while (i > 1 && a[i] > a[i / 2]) {
            swap(a[i], a[i / 2]);
            i = i / 2;
        }
    }

    void topBottomAdjust(int i) {
        int child;
        while (2 * i <= size) {
            child = 2 * i;
            if (child + 1 <= size && a[child + 1] > a[child])
                child++;
            if (a[i] >= a[child])
                break;
            swap(a[i], a[child]);
            i = child;
        }
    }

public:
    bool insert(int val) {
        if (size >= 100)
            return false;
        size++;
        a[size] = val;
        bottomTopAdjust(size);
        return true;
    }

    int showMax() {
        if (size == 0)
            return -1; // Assuming -1 is an invalid value
        return a[1];
    }

    int showSize() {
        return size;
    }

    bool deleteRoot() {
        if (size == 0)
            return false;
        swap(a[1], a[size]);
        size--;
        topBottomAdjust(1);
        return true;
    }

    void buildHeap() {
        for (int i = size / 2; i >= 1; i--) {
            topBottomAdjust(i);
        }
    }

    void sort() {
        int heapSize = size;
        while (size > 1) {
            swap(a[1], a[size]);
            size--;
            topBottomAdjust(1);
        }
        size = heapSize; // Restore the original size
    }

    void bfs() {
        if (size == 0)
            return;
        int level = 1;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            if (parent == level) {
                cout << endl;
                level = level * 2;
            }
            cout << a[parent] << " ";
            if (2 * parent <= size) q.push(2 * parent);
            if (2 * parent + 1 <= size) q.push(2 * parent + 1);
        }
    }
};

int main() {

    Heap heap;

    while (true) {
        cout << "1. Insert    2. Show Max    3. Delete Max    4. Sort    5. Level    6. Build Heap    7. End" << endl << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b)   cout << y << " is inserted in the heap" << endl;
        }

        else if (choice == 2) {
            if (heap.showSize() != 0)  cout << "Max Element: " << heap.showMax();
            else    cout << "No element in the heap" << endl;
        }

        else if (choice == 3) {
            bool b = heap.deleteRoot();
            if (b)   cout << "Root deleted from heap";
            else    cout << "Heap is empty";
            cout << endl;
        }

        else if (choice == 4) {
            heap.sort();
        }

        else if (choice == 5) {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        }
        else if (choice == 6) {
            if (heap.showSize() == 0)
                cout << "Heap is Empty!" << endl;
            else
                heap.buildHeap();
        }
        else if (choice == 7) {
            break;
        }

        else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }

    return 0;
}


/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
*/

