#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numberOfVertices;
    list<int> *adj;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

Graph::Graph(int vertices) {
    numberOfVertices = vertices;
    adj = new list<int>[numberOfVertices];
    visited = new bool[numberOfVertices];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_front(dest);
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adj[vertex];
    cout << vertex << " ";
    for(auto i = adjList.begin(); i != adjList.end(); i++) {
        if(!visited[*i]) {
            DFS(*i);
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
    return 0;
}