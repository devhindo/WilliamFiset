# Depth First Search Algorithm

*Time Complexity: $O(V+E)$*
V : vertices.
E : Edges.

- By itself it isn't so useful, but when augmented to perform other tasks such as connectivity, or finding bridges/articulation points then DFS really shines.
- a DFS plunges depth first into a graph without regard for which edge it takes next until it cannot go any further at which point it backtracks and continue.

[DFS source code](DFS.cpp)

## Connected Components

- sometimes the graph is split into multiple disjoint components and it's useful to be able identify and count these components.
- we can use a DFS search to identify the connected components of a graph.
- we give each a group an id.
- the basic algorithm is to run a DFS search at every node except if that node is already been visited and mark all the reachable nodes as beeing part of the same component using the same id.
