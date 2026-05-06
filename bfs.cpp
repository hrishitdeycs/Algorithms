#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    // start BFS from the starting node
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // print current node
        cout << node << " ";
        // visit all adjacent nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        // assuming undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "BFS traversal: ";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(i, adj, visited);
        }
    }
    return 0;
}
/*
Enter number of vertices and edges: 5 4
Enter edges (u v):
0 1
0 2
1 3
3 4
*/
