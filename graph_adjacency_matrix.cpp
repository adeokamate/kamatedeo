#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
    bool isDirected;

public:
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        isDirected = directed;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int u, int v, int weight = 1) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex index!\n";
            return;
        }
        adjMatrix[u][v] = weight;
        if (!isDirected)
            adjMatrix[v][u] = weight;
    }

    void removeEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex index!\n";
            return;
        }
        adjMatrix[u][v] = 0;
        if (!isDirected)
            adjMatrix[v][u] = 0;
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:\n";
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int vertices, edges, u, v, weight;
    bool directed;
    char choice;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    Graph g(vertices, directed);

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; ++i) {
        cout << "Enter edge " << i + 1 << " (u v weight): ";
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    do {
        cout << "\nMenu:\n1. Add Edge\n2. Remove Edge\n3. Display Matrix\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter edge (u v weight): ";
            cin >> u >> v >> weight;
            g.addEdge(u, v, weight);
            break;
        case '2':
            cout << "Enter edge to remove (u v): ";
            cin >> u >> v;
            g.removeEdge(u, v);
            break;
        case '3':
            g.displayMatrix();
            break;
        case '4':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != '4');

    return 0;
}
