//MCM
#include <bits/stdc++.h>
using namespace std;

const int big = 99999999;

int m[100][100];
int s[100][100];
int d[100];

int MCM(int i, int j) {
    if (i == j) return 0;
    if (m[i][j] != 99999)   return m[i][j];
    int cost = 9999999;
    for (int k = i; k < j; k++) {
        cost = MCM(i, k) + MCM(k + 1, j) + d[i - 1] * d[k] * d[j];
        if (cost < m[i][j]) {
            m[i][j] = cost;
            s[i][j] = k;
        }
    }
    return m[i][j];
}

void printOptimalOrder(int i, int j) {
    if (i == j) cout << "A" << i;
    else {
        cout << "(";
        printOptimalOrder(i, s[i][j]);
        cout << " x ";
        printOptimalOrder(s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    int row[100], col[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> row[i] >> col[i];
        d[i] = row[i];
        d[i + 1] = col[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = 99999;
            s[i][j] = -1;
        }
    }

    cout << "Minimum Cost: " << MCM(1, n) << endl;
    cout << "Optimal Order: ";
    printOptimalOrder(1, n);
    cout << endl;

    return 0;
}
