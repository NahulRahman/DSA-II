//01 using backtracking
#include <bits/stdc++.h>
using namespace std;
int c = 4; // Static capacity
int n = 5; // Static number of items
int p[2005] = {8, 4, 0, 5, 3};//profit
int w[2005] = {1, 2, 3, 2, 2};//wt

int knapsack(int i, int j) {
  if (i < 0 || j <= 0) return 0;
  if (i == 0) {
    if (w[i] <= j) return p[i];
    else return 0;
  }
  int v1 = 0 + knapsack(i - 1, j);
  int v2 = INT_MIN;
  if (w[i] <= j) v2 = p[i] + knapsack(i - 1, j - w[i]);
  return max(v1, v2);
}

int main() {
  cout << "Static input:" << endl;
  for (int i = 0; i < n; i++) cout << w[i] << " " << p[i] << " ";
  cout << endl;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= c; j++) cout << knapsack(i, j) << " ";
     cout << endl;
  }
  cout << "Max cost: " << knapsack(n - 1, c) << endl;
  return 0;
}
