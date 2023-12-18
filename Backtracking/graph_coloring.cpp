//graphcoloring
#include <bits/stdc++.h>
using namespace std;

vector<int> color;
vector<int> vertex;
int m = 3; // Number of colors
int v = 4; // Number of vertices
int ed = 4; // Number of edges
vector<int>* graph;
void AddEdge(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

bool IsSafe(int v, int c) {
  for (int i = 0; i < graph[v].size(); i++) if (vertex[graph[v][i]] == c)  return false;
  return true;
}

bool Coloring(int ve) {
  if (ve == v)  return true;
  else {
    for (int i = 0; i < m; i++) {
      int x = IsSafe(ve, color[i]);
      if (x == 1) {
        vertex[ve] = color[i];
        if (Coloring(ve + 1) == true)   return true;
        else  vertex[ve] = -1;
      }
    }  return false;
  }
}

int main() {
  int i;
  graph = new vector<int>[v];
  for (i = 0; i < v; i++)     vertex.push_back(-1);
  for (i = 0; i < m; i++)    color.push_back(i + 1); // 1=R, 2=G, 3=B
  AddEdge(0, 1);
  AddEdge(0, 2);
  AddEdge(1, 2);
  AddEdge(2, 3);
  AddEdge(3, 0);
  if (Coloring(0))    cout << "Graph was colored Successfully\n";
  else   cout << "Graph can not be colored\n";
  for (i = 0; i < vertex.size(); i++) {
    if (vertex[i] == 1)   cout << "R" << " ";
    else if (vertex[i] == 2) cout << "G" << " ";
    else  cout << "B" << " ";
  }
  delete[] graph;
  return 0;
}
