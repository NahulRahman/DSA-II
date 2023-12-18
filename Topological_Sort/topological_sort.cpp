//the code runs perfect in an online compiler, but it shows many problem in codeblocks
//topo-sort
#include <bits/stdc++.h>
using namespace std;

void topo_sort(int vertices, int edges) {
    vector<char> ans;
    queue<char> q;
    map<char, vector<char> > graph;
    map<char, int> inDegree;

    vector < pair<char, char> > edgeList = {{'A', 'B'},{'A', 'C'},{'B', 'D'},{'B', 'E'},{'C', 'E'},{'D', 'F'},{'E', 'F'}};

    for (int i = 0; i < edges; i++) {
        char a = edgeList[i].first;
        char b = edgeList[i].second;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    for (char c = 'A'; c <= 'F'; c++) if (inDegree[c] == 0) q.push(c);

    while (!q.empty()) {
        char v = q.front();
        q.pop();
        ans.push_back(v);
        for (int i = 0; i < graph[v].size(); i++) {
            char u = graph[v][i];
            inDegree[u]--;
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1)  cout << "->";
    }
}

int main() {
    int vertices = 6;
    int edges = 7;
    topo_sort(vertices, edges);
    return 0;
}
