# Overview of algorithms in Graph Theory

[video](https://youtu.be/87X57ldq1ok)

## Table of Contents

- [Introduction](#introduction)
- [Questions to ask yourself when you encounter a graph problem](#questions-to-ask-yourself-when-you-encounter-a-graph-problem)
- [Shortest path problem](#shortest-path-problem)
- [Is there a path](#is-there-exist-a-path-between-node-a-and-node-b)
- [Negative cycles](#negative-cycles)
- [Strongly Connected Components](#strongly-connected-components)
- [Traveling Salesman Problem](#traveling-salesman-problem)
- [Bridges](#bridges)
- [Minimum Spanning Tree](#minimum-spanning-tree)
- [Network flow: max flow](#network-flow-max-flow)

## Introduction

*A lot of problems you will encounter can often be reduced to a famous well-known problem or some varient of it. So it is important to know the most common problems and their solutions.*

## Questions to ask yourself when you encounter a graph problem

- How to store and represent the graph in the problem?
- Directed or undirected?
- Edges are Weighted or unweighted?
- Is the graph likely to be sparse or dense with edges?
- Should I use an adjacency matrix, adjacency list, an edge list or other structure to represent the graph efficiently?

## Shortest path problem

- Description: Given a weighted graph, find the sortest path of edges from node A to node B.
- **Algorithms**: BFS (unweighted graph), Dijkstra's , Bellman-Ford, Floyd-Warshall, A*, and many more.

## Is there exist a path between node A and node B?

- Typical solution: Use union find data structure or any search algorithm (DFS or BFS).

## Negative cycles

- **Despcription**: Does my weighted gigraph have any negative cycles? If so, where?
- Detecting negative cycles in a directed graph.
- In the context of finding the shortest path, negative cycles are a like a trap because they can cause the shortest path to be infinite.
- **Algorithms**: Bellman-Ford, Floyd-Warshall. known for detecting negative cycles in general.

## Strongly Connected Components

- This is analogous to finding connected components of an undirected graph but for directed graphs.
- We are looking for self-contained cycles within the graph where every vertex in a given cycle should be able to reach any other vertex in the same cycle.
- useful in many algorithms as an intermediate step.
- **Algorithms**: Tarjan's and Kosaraju's algorithm.

## Traveling Salesman Problem

- Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?
- Note that the graph is directed so the path from A to B is not the same as the path from B to A in terms of shortest path.
- **Algorithms**: Held-Karp, Branch and Bound, and many approximation algorithms.
- It's NP-Hard meaning it's very computationally challenging to solve.

## Bridges

- Finding bridges in a graph.
- A bridge is an edge that if removed, will increase the number of connected components in the graph.
- Bridges are important in graph theory because they hint at weak points in the graph.
- Articulation points / cut vertices : are similar to bridges but they are vertices instead of edges.

## Minimum Spanning Tree

- A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
- **Algorithms**: Kruskal's, Prim's, Boruvka's.

## Network flow: max flow

- Finding the maximum flow in a special type of graph called flow network.
- Flow networks are networks where edge weights represent the capacity of the edge.
- How much flow can we push through the network from source to target? That's because there might be a bottleneck in the network that limits the amount of flow we can push through.
- with these maximum flow problems we can identify the bottlenecks that slow down the whole network and fix the edges that has lower capacity.
- **Algorithms**: Ford-Fulkerson, Edmonds-Karp, Dinic's, Push-relabel algorithm.
