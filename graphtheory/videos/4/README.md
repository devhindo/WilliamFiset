# Depth First Search

Table of Contents

- [Complexity](#complexity)
- [Depth First Search Algorithm](#depth-first-search-algorithm)
- [Connected Components](#connected-components)
- [DFS can do more](#dfs-can-do-more)

## Complexity

*Time Complexity: $O(V+E)$*
V : vertices.
E : Edges.

## Depth First Search Algorithm

- By itself it isn't so useful, but when augmented to perform other tasks such as connectivity, or finding bridges/articulation points then DFS really shines.
- a DFS plunges depth first into a graph without regard for which edge it takes next until it cannot go any further at which point it backtracks and continue.

[DFS source code](DFS.cpp)

## Connected Components

- sometimes the graph is split into multiple disjoint components and it's useful to be able identify and count these components.
- we can use a DFS search to identify the connected components of a graph.
- we give each a group an id.
- the basic algorithm is to run a DFS search at every node except if that node is already been visited and mark all the reachable nodes as beeing part of the same component using the same id.

[Connected Components source code](ConnectedComponents.cpp)

## DFS can do more

### we can augment the DFS algorithm to

- Compute a graph minimum spanning tree.
- Detect cycles in a graph.
- Check if a graph is bipartite.
Find strongly connected components in a graph.
- Topologically sort a graph.
- Find bridges and articulation points in a graph.
- Find augmenting paths in a flow network.
- Generate mazes.
- and many more.
