
#include <iostream>
#include <queue>
using namespace std;

int graph[20][20];
bool visited[20];
int n;

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "DFS: ";
    DFS(start);

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
