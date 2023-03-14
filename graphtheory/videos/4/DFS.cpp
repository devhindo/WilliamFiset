#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numberOfVertices;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex, bool* visited);
};

Graph::Graph(int vertices) {
    numberOfVertices = vertices;
    adj = new list<int>[numberOfVertices];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_front(dest);
}

void Graph::DFS(int vertex, bool* visited) {
    visited[vertex] = true;
    list<int> adjList = adj[vertex];
    cout << vertex << " ";
    for(auto i = adjList.begin(); i != adjList.end(); i++) {
        if(!visited[*i]) {
            DFS(*i, visited);
        }
    }
}

int main() {
    int numberOfVertices = 4;
    Graph g(numberOfVertices);
    bool *visited;
    visited = new bool[numberOfVertices];
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2,visited);
    return 0;
}