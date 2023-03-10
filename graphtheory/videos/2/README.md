# 2. Graph Theory Introduction

[video](https://youtu.be/eQA-m22wjTQ)

It's really important to be able to recognize what type of graph you're working with or what type of graph you need to solve a particular problem.

## Types of Graphs

- **Undirected Graphs** - edges have no direction.
- **Directed Graphs** - edges have direction.
- **Weighted Graphs** - edges have a weight to represent arbitrary values. You also need to specify whether the graph is directed or undirected.
- **Special Graphs:**
  - **Trees**
    - undirected, acyclic `having no cycles` , connected graphs.
    - a graph with n nodes and n-1 edges.
  - **Rooted Trees**
    - a tree with a designated root node where every edge either points away from or towards the root node. When edges point away from the root the graph is called an **arborescence** `out-tree` and **anti-arborescence** `in-tree` otherwise.
  - **Directed Acyclic Graphs (DAGs)**
    - directed, acyclic graphs `no cycles`.
    - Cool fact: All out-trees are DAGs but not all DAGs are out-trees.
  - **Bipartite Graphs**
    - graphs where the nodes can be split into two disjoint sets such that every edge connects a node in one set to a node in the other set.
    - a fancy way of saying that the graph can be colored with two colors such that no two adjacent nodes have the same color. Or, no two nodes that are connected by an edge have the same color.
    - **Complete Graphs**
      - there is a unique edge between every pair of nodes.
      - considered as worst case scenario for graph algorithms which could be useful in stuying the performance of algorithms on ordinary graphs.

## Representing Graphs

*The choice of data structure for representing graphs is very important. The wrong choice can lead to very inefficient algorithms. This can have a huge impact on performance.*

### Adjacency Matrix

- $V*V$ matrix where $V$ is the number of nodes in the graph.
- the cell $m[i][j]$ represents the weight of the edge between node $i$ and node $j$.

| Pros | Cons |
| :--: | :--: |
| Space efficient for representing dense graphs | Requires $O(V^2)$ |
| Edge weight lookup is $O(1)$ | Iterating over all edges takes $O(V^2)$ time |
| Simplest graph representation

- *In general it's fine for dense graphs with lots of edges but it isn't so great for spares graphs*

### Adjacency List

- A way to represent the graph as a map of nodes to lists of edges.
- The ideo is that each node tracks all of its outgoing edges.

| Pros | Cons |
| :--: | :--: |
| Space efficient for sparse graphs | Less space efficient for dense graphs |
| Iterating over all edges is efficient | Requires $O(E)$ space |
| | Slightly more complex graph representation |

### Edge List

- A wat to represent the graph as an **unordered list of edges**.
- list of $(u,v,w)$.

| Pros | Cons |
| :--: | :--: |
| Space efficient for sparse graphs | Less space efficient for dense graphs |
| Iterating over all edges is efficient | Edge weight lookup is $O(E)$ |
| very simple structure | |
