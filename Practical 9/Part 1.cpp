#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next, graph, visited);
        }
    }
}

void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, edges;
    
    cout << "Enter number of buildings: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads (building1 building2):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    vector<bool> visited(n, false);

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, graph, n);

    return 0;
}