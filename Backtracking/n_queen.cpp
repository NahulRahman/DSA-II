//n queen
#include <bits/stdc++.h>
#define n 4//change the number n like 4,5,6,7 it'll change your answer
using namespace std;
int a[n + 1][n + 1];
int totalSolutions = 0;

bool is_safe(int row, int col) {
    for (int i = 1; i <= row; i++) if (a[i][col] == 1) return false;
    for (int i = row, j = col; i >= 1 && j >= 1; i--, j--)  if (a[i][j] == 1) return false;
    for (int i = row, j = col; i >= 1 && j <= n; i--, j++)  if (a[i][j] == 1) return false;
    return true;
}

void n_queen(int row) {
    if (row == n + 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        totalSolutions++;
    }

    for (int col = 1; col <= n; col++) {
        if (is_safe(row, col)) {
            a[row][col] = 1;
            n_queen(row + 1);
            a[row][col] = 0;
        }
    }
}

int main() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    n_queen(1);
    cout << "Total solutions found: " << totalSolutions << endl;
}
