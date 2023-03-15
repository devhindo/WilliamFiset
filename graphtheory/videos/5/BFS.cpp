#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int src, int dest);
    vector<int> solve(int s);
    list<int> BFS(int s, int e);
    
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest) {
    adj[src].push_front(dest);
}



vector<int> Graph::solve(int s) {
    queue<int> q;
    q.push(s);
    vector<bool>visited(V, false);
    visited[s] = true;
    vector<int>previous(V,-1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        auto neighbours = adj[node];
        for(auto neighbour: neighbours) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                previous[neighbour] = node;
            }
        }
        return previous;
    }
}

list<int> reconstructPath(int s, int e, vector<int> prev) {
    list<int> path;
    for(int at = e; at != -1; at = prev[at]) {
        path.push_front(at);
    }
    path.reverse();
    if(path.front() == s)
        return path;
    return list<int>();
}

list<int> Graph::BFS(int s, int e) {
    vector<int> prev = solve(s);
    return reconstructPath(s, e, prev);
}

