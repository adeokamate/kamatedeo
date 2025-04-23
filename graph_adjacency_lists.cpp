
#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i); // Undirected graph
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter each edge (u v) on a new line:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Check for valid vertex numbers
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge: (" << u << ", " << v << "). Skipping..." << endl;
            continue;
        }

        addEdge(adj, u, v);
    }

    cout << "\nAdjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}
