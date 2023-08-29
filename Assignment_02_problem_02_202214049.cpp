#include <iostream>
#include <queue>
using namespace std;

class PriorityQueue {
private:
    pair<int, int> a[101]; // Pair of key and value
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

private:
    void bottomTopAdjust(int i) {
        while (i > 1 && a[i].first > a[i / 2].first) {
            swap(a[i], a[i / 2]);
            i = i / 2;
        }
    }

    void topBottomAdjust(int i) {
        int child;
        while (2 * i <= size) {
            child = 2 * i;
            if (child + 1 <= size && a[child + 1].first > a[child].first)
                child++;
            if (a[i].first >= a[child].first)
                break;
            swap(a[i], a[child]);
            i = child;
        }
    }

public:
    bool insert(int key, int val) {
        if (size >= 100)
            return false;
        size++;
        a[size] = make_pair(key, val);
        bottomTopAdjust(size);
        return true;
    }

    pair<int, int> getMax() {
        if (size == 0)
            return make_pair(-1, -1); // Assuming (-1, -1) is an invalid value
        return a[1];
    }

    pair<int, int> extractMax() {
        if (size == 0)
            return make_pair(-1, -1); // Assuming (-1, -1) is an invalid value
        pair<int, int> maxElement = a[1];
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
                cout << "(" << a[parent].first << "," << a[parent].second << ") ";
                if (2 * parent <= size) q.push(2 * parent);
                if (2 * parent + 1 <= size) q.push(2 * parent + 1);
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue priorityQueue;

    while (true) {
        cout << "1. Insert    2. Get Max    3. Extract Max  4. Level Order Traversal 5. End" << endl << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert Key and Value: ";
            int key, value;
            cin >> key >> value;
            bool b = priorityQueue.insert(key, value);

            if (b)   cout << "(" << key << "," << value << ") is inserted in the priority queue" << endl;
        }
        else if (choice == 2) {
            pair<int, int> maxElement = priorityQueue.getMax();
            if (maxElement.first != -1)
                cout << "Max Element: (" << maxElement.first << "," << maxElement.second << ")";
            else
                cout << "No element in the priority queue" << endl;
        }
        else if (choice == 3) {
            pair<int, int> maxElement = priorityQueue.extractMax();
            if (maxElement.first != -1)
                cout << "Max element extracted: (" << maxElement.first << "," << maxElement.second << ")";
            else
                cout << "No element in the priority queue" << endl;
        }
        else if (choice == 4) {
            cout << "Level Wise Traversal of the priority queue:" << endl;
            priorityQueue.bfs();
            cout << endl;
        }
        else if (choice == 5)
            break;
        else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }

    return 0;
}

