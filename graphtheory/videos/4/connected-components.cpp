#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numberOfVertices;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex, bool* visited, int *components, int& count);
    void findComponent(bool* visited, int* components, int& count);
};

Graph::Graph(int vertices) {
    numberOfVertices = vertices;
    adj = new list<int>[numberOfVertices];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_front(dest);
}

void Graph::DFS(int vertex, bool* visited, int *components, int& count) {
    visited[vertex] = true;
    components[vertex] = count;
    list<int> adjList = adj[vertex];
    for(auto i = adjList.begin(); i != adjList.end(); i++) {
        if(!visited[*i]) {
            DFS(*i, visited, components, count);
        }
    }
}

void Graph::findComponent(bool* visited, int* components, int& count) {
    for(int i = 0; i < numberOfVertices; i++) {
        if(!visited[i]) {
            count++;
            DFS(i, visited, components, count);
        }
    }
}

int main() {
    int numberOfVertices = 4;
    Graph g(numberOfVertices);
    bool *visited;
    visited = new bool[numberOfVertices];
    int *components;
    components = new int[numberOfVertices];
    int count = 0;
    // generate test case with 5 components
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    g.findComponent(visited, components, count);
    for(int i = 0; i < numberOfVertices; i++) {
        cout << components[i] << " ";
    }
    cout << endl;
    cout << count;
    return 0;
}