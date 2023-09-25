#include <algorithm>
#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

struct edge {
    char v;
    int w;
};

struct node {
    char vertex;
    int d;
    node* parent;
    vector<edge> adj;
};

class Graph {
public:
    int V;
    node* nodes;
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
            if (nodes[i].vertex == u) {
                nodes[i].adj.push_back(e);
            }
        }
    }

    void printPath(node* s) {
        if (s->parent != NULL) {
            printPath(s->parent);
            cout << " ----> ";
        }
        cout << s->vertex << " ";
    }

    void INITIALIZE_SINGLE_SOURCE(char s) {
        for (int i = 0; i < V; i++) {
            if (nodes[i].vertex == s) {
                nodes[i].d = 0;
            }
        }
    }

    int relax(char u, char v, int w) {
        int u_idx = -1, v_idx = -1;
        for (int i = 0; i < V; i++) {
            if (nodes[i].vertex == u) {
                u_idx = i;
            }
            if (nodes[i].vertex == v) {
                v_idx = i;
            }
        }
        if (u_idx != -1 && v_idx != -1) {
            if (nodes[u_idx].d != INT_MAX && nodes[u_idx].d + w < nodes[v_idx].d) {
                nodes[v_idx].d = nodes[u_idx].d + w;
                nodes[v_idx].parent = &nodes[u_idx];
                return 1;
            }
        }
        return 0; // No relaxation occurred
    }
};

bool BELLMAN_FORD(Graph& G, char s) {
    G.INITIALIZE_SINGLE_SOURCE(s);

    for (int i = 0; i < G.V - 1; i++) {
        for (int j = 0; j < G.V; j++) {
            for (const edge& e : G.nodes[j].adj) {
                G.relax(G.nodes[j].vertex, e.v, e.w);
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < G.V; j++) {
        for (const edge& e : G.nodes[j].adj) {
            int u_idx = -1, v_idx = -1;
            for (int k = 0; k < G.V; k++) {
                if (G.nodes[k].vertex == G.nodes[j].vertex) {
                    u_idx = k;
                }
                if (G.nodes[k].vertex == e.v) {
                    v_idx = k;
                }
            }
            if (u_idx != -1 && v_idx != -1) {
                if (G.nodes[u_idx].d != INT_MAX && G.nodes[u_idx].d + e.w < G.nodes[v_idx].d) {
                    cout << "Negative Weighted cycle present. No solution!!" << endl;
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    Graph G(5);
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

    if (BELLMAN_FORD(G, 'A')) {
        for (int i = 0; i < G.V; i++) {
            cout << "\nShortest Path from A to " << G.nodes[i].vertex << ": ";
            G.printPath(&G.nodes[i]);
            cout << " (Cost: " << G.nodes[i].d << ")" << endl;
        }
    }

    return 0;
}
