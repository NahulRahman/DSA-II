#include<bits/stdc++.h>
using namespace std;

// Define structures for edge and node
struct edge {
    char v;
    int w;
};

struct node {
    char vertex;
    int d;
    node *parent;
    vector<edge> adj; // adjacent vertices with weight
};

class Graph {
public:
    int V; // number of vertices/nodes in graph
    node *nodes; // vertices of the graph

    Graph(int v) {
        V = v;
        nodes = new node[V];
        for (int i = 0; i < V; i++) {
            nodes[i].vertex = 'A' + i;
            nodes[i].d = INT_MAX; // Initialize distances to infinity
            nodes[i].parent = nullptr;
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
        if (s->parent != nullptr) {
            this->printPath(s->parent);
            cout << " ----> ";
        }
        cout << s->vertex << " ";
    }

    void INITIALIZE_SINGLE_SOURCE(char s) {
        for (int i = 0; i < V; i++) {
            if (nodes[i].vertex == s) {
                nodes[i].d = 0;
                break;
            }
        }
    }

    int relax(char u, char v, int w) {
        int u_idx = u - 'A';
        int v_idx = v - 'A';

        if (nodes[u_idx].d != INT_MAX && nodes[u_idx].d + w < nodes[v_idx].d) {
            nodes[v_idx].d = nodes[u_idx].d + w;
            nodes[v_idx].parent = &nodes[u_idx];
            return 1; // Relaxation performed
        }
        return 0; // No relaxation performed
    }
};

bool BELLMAN_FORD(Graph &G, char s) {
    G.INITIALIZE_SINGLE_SOURCE(s);

    for (int i = 0; i < G.V - 1; i++) {
        for (int j = 0; j < G.V; j++) {
            for (const edge &e : G.nodes[j].adj) {
                G.relax(G.nodes[j].vertex, e.v, e.w);
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < G.V; j++) {
        for (const edge &e : G.nodes[j].adj) {
            if (G.relax(G.nodes[j].vertex, e.v, e.w)) {
                cout << "Negative Weighted cycle present. No solution!!" << endl;
                return false;
            }
        }
    }

    return true;
}

int main() {
    Graph G(5); // 5 is the number of vertices in the graph
    for (int i = 0; i < 5; i++) {
        cout << G.nodes[i].vertex << endl;
    }
    G.AddWeightedEdge('A', 'B', 3);
    G.AddWeightedEdge('A', 'C', 1);
    G.AddWeightedEdge('B', 'D', 1);
    G.AddWeightedEdge('B', 'E', 2);
    G.AddWeightedEdge('C', 'B', 1);
    G.AddWeightedEdge('C', 'D', 4);
    G.AddWeightedEdge('D', 'E', 3);
    G.AddWeightedEdge('D', 'C', -10); // Negative weight

    if (BELLMAN_FORD(G, 'A')) {
        for (int i = 0; i < G.V; i++) {
            cout << "\nShortest Path from A to " << G.nodes[i].vertex << endl;
            G.printPath(&G.nodes[i]);
        }
    } else {
        cout << "Negative Weighted cycle present. No solution!!" << endl;
    }
    return 0;
}
