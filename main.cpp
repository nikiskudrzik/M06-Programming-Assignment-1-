#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int> >& adjList, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // loop through neighbors
    for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];

        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    // create adjacency list
    vector<vector<int> > adjList(vertices);

    // input edges
    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    dfs(startNode, adjList, visited);

    return 0;
}