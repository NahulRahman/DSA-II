#include<bits/stdc++.h>
using namespace std;

struct edge {
    char v;
    int w;
};

struct node {
    char vertex;
    int d;
    node *parent;
    vector<edge> adj;
};

class Graph {
public:
    int V;
    node *nodes;

    Graph(int v) {
        V = v;
        nodes = new node[V];
        for (int i = 0; i < V; i++) {
            nodes[i].vertex = 'A' + i;
            nodes[i].d = INT_MAX;
            nodes[i].parent = NULL;
        }
    }

    void AddWeightedEdge(char u, char n, int w) {
        edge e;
        e.v = n;
        e.w = w;
        for (int i = 0; i < V; i++) {
            if (nodes[i].vertex == u)
                nodes[i].adj.push_back(e);
        }
    }

    void printPath(node *s) {
        if (s->parent != NULL) {
            this->printPath(s->parent);
            cout << " ----> ";
        }
        cout << s->vertex << " ";
    }

    void INITIALIZE_SINGLE_SOURCE(char s) {
        for (int i = 0; i < V; i++) {
            if (nodes[i].vertex == s)
                nodes[i].d = 0;
        }
    }

    int relax(char u, char v, int w) {
        int uIndex = u - 'A';
        int vIndex = v - 'A';
        if (nodes[uIndex].d != INT_MAX && nodes[uIndex].d + w < nodes[vIndex].d) {
            nodes[vIndex].d = nodes[uIndex].d + w;
            nodes[vIndex].parent = &nodes[uIndex];
            return 1;
        }
        return 0;
    }
};

bool BELLMAN_FORD(Graph G, char s) {
    G.INITIALIZE_SINGLE_SOURCE(s);
    for (int i = 0; i < G.V - 1; i++) {
        for (int u = 0; u < G.V; u++) {
            for (edge e : G.nodes[u].adj) {
                G.relax(G.nodes[u].vertex, e.v, e.w);
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < G.V; u++) {
        for (edge e : G.nodes[u].adj) {
            if (G.relax(G.nodes[u].vertex, e.v, e.w))
                return false; // Negative weight cycle detected
        }
    }

    return true; // No negative weight cycle
}

int main() {
    Graph G(5);

    G.AddWeightedEdge('A', 'B', 3);
    G.AddWeightedEdge('A', 'C', 1);
    G.AddWeightedEdge('B', 'D', 1);
    G.AddWeightedEdge('B', 'E', 2);
    G.AddWeightedEdge('C', 'B', 1);
    G.AddWeightedEdge('C', 'D', 4);
    G.AddWeightedEdge('D', 'E', 3);

    if (BELLMAN_FORD(G, 'A')) {
        for (int i = 0; i < G.V; i++) {
            cout << "\nShortest Path from A to " << G.nodes[i].vertex << endl;
            G.printPath(&G.nodes[i]);
            cout << " (Distance: " << G.nodes[i].d << ")" << endl;
        }
    } else {
        cout << "Negative Weighted cycle present. No solution!!" << endl;
    }

    return 0;
}
