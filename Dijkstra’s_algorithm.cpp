#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
void printPath(int node, vector<int> &parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}
void dijkstra(int n, vector<pair<int,int>> adj[], int source) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (currentDist + weight < dist[v]) {
                dist[v] = currentDist + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Shortest paths from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To node " << i << " = Distance: " << dist[i] << " | Path: ";
        if (dist[i] == INF) {
            cout << "No path\n";
            continue;
        }
        printPath(i, parent);
        cout << endl;
    }
}
int main() {
    int n = 5;
    vector<pair<int,int>> adj[n];
    adj[0].push_back(make_pair(1, 2));
    adj[0].push_back(make_pair(2, 4));
    adj[1].push_back(make_pair(2, 1));
    adj[1].push_back(make_pair(3, 7));
    adj[2].push_back(make_pair(4, 3));
    adj[3].push_back(make_pair(4, 1));
    int source = 0;
    dijkstra(n, adj, source);
    return 0;
}
