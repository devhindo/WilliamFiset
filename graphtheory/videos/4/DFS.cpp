#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adj;
    vector<bool>visited;

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n);
        visited.resize(n, false);
    }
    void addEdge(int u, int v);
    void DFS(int v);

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int s) {
    if(visited[s]) return;
    visited[s] = true;
    cout << s << " ";
    vector<int> neighbours = adj[s];
    for(auto v: neighbours) {
        DFS(v);
    }

}
};


int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.DFS(0);
    return 0;
}