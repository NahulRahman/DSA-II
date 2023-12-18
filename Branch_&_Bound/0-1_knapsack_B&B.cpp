//0-1 knapsack using B&B
#include <bits/stdc++.h>
using namespace std;

class Item {
public:
  int weight;
  int value;
};

class Node {
public:
  int level;
  int profit;
  float ub;
  int weight;
};

bool custom(const Item& u, const Item& v) {
  return (float)u.value / (float)u.weight > (float)v.value / (float)v.weight;
}

int knapsack(int W, Item a[], int n) {
  sort(a, a + n, custom);

  queue<Node> q;
  Node u, v;
  u.level = -1;
  u.profit = 0;
  u.weight = 0;
  u.ub = 0;
  q.push(u);

  int maxProfit = 0;

  while (!q.empty()) {
    u = q.front();
    q.pop();

    if (u.level == n - 1) continue;

    v.level = u.level + 1;
    v.weight = u.weight + a[v.level].weight;
    v.profit = u.profit + a[v.level].value;

    if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;

    v.ub = v.profit + (W - v.weight) * (a[v.level + 1].value / (float)a[v.level + 1].weight);

    if (v.ub > maxProfit) q.push(v);

    v.weight = u.weight;
    v.profit = u.profit;
    v.ub = v.profit + (W - v.weight) * (a[v.level + 1].value / (float)a[v.level + 1].weight);

    if (v.ub > maxProfit) q.push(v);
  }

  return maxProfit;
}

int main() {
  int W = 5, n = 3;
  Item items[] = {{2, 3}, {1, 2}, {3, 4}};

  // Uncomment below for user input

  // cin >> W >> n;
  // Item items[n];
  // for (int i = 0; i < n; i++)
  //   cin >> items[i].weight >> items[i].value;

  cout << knapsack(W, items, n);

  return 0;
}
