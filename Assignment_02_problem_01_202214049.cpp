#include<bits/stdc++.h>
using namespace std;

class MaxPriorityQueue {
private:
    int a[101], size;

public:
    MaxPriorityQueue() {
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
            if (child + 1 <= size && a[child + 1] > a[child]) child++;
            if (a[i] >= a[child]) break;
            swap(a[i], a[child]);
            i = child;
        }
    }

public:
    bool insert(int val) {
        if (size >= 100) return false;
        size++;
        a[size] = val;
        bottomTopAdjust(size);
        return true;
    }

    int getMax() {
        if (size == 0) return -1; // Assuming -1 is an invalid value
        return a[1];
    }

    int extractMax() {
        if (size == 0) return -1; // Assuming -1 is an invalid value
        int maxElement = a[1];
        swap(a[1], a[size]);
        size--;
        topBottomAdjust(1);
        return maxElement;
    }

    void bfs() {
    if (size == 0) return;
    int level = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            int parent = q.front();
            q.pop();
            cout << a[parent] << " ";
            if (2 * parent <= size) q.push(2 * parent);
            if (2 * parent + 1 <= size) q.push(2 * parent + 1);
        }
        cout << endl;
    }
}

};

int main() {
    MaxPriorityQueue maxPriorityQueue;

    while (true) {
        cout << "1. Insert    2. Get Max    3. Extract Max  4. Level Order Traversal 5. End" << endl << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = maxPriorityQueue.insert(y);

            if (b)   cout << y << " is inserted in the priority queue" << endl;
        }
        else if (choice == 2) {
            if (maxPriorityQueue.getMax() != -1)  cout << "Max Element: " << maxPriorityQueue.getMax();
            else    cout << "No element in the priority queue" << endl;
        }
        else if (choice == 3) {
            if (maxPriorityQueue.getMax() != -1)  cout << "Max element extracted: " << maxPriorityQueue.extractMax();
            else    cout << "No element in the priority queue" << endl;
        }
        else if (choice == 4) {
            cout << "Level Wise Traversal of the priority queue:" << endl;
            maxPriorityQueue.bfs();
            cout << endl;
        }
        else if (choice == 5) break;
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

