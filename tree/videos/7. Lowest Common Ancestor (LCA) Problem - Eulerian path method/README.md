# 7. Lowest Common Ancestor (LCA) Problem - Eulerian path method

[video](https://youtu.be/sD1IoalFomA?si=bp2qnHE5UaUuu2Ho)

## 7.1. Intro

- the `lowest common ancestor` (LCA) of two nodes $a$ and $b$ in a `rooted tree` is the deepest node $c$ that has both $a$ and $b$ as descendants, where we define each node to be descendants (where a node can be a descendant of itself)

- the LCA problem has several applications in computer science:
  - finding the distance between two nodes in a tree
  - Inheritance heirarchies in Object Oriented Programming
  - inside the subrotines of several advanced algorithms and data structures

## 7.2. LCA Algorithms

- there are a diverse number of popular algorithms for finding the LCA of two nodes in a tree
  - Tarjan's offline LCA algorithm
  - Heavy-light decomposition
  - Binary lifting
  - Euleirian tour + Range Minimum Query (RMQ)
  
<i>Today, we are going to cover the `Euleirian tour + Range Minimum Query (RMQ)` method</i>

## 7.3. Eulerian Tour

- this method can answer LCA queries in $O(1)$ time with $O(nlogn)$ pre-processing when using a `Spare Table` to do the RMQs
- however, the pre-processing can be reduced to $O(n)$ with the Farach-Colton and Bender optimization
- you can do this $LCA(10,LCA(12,16))$ to find the LCA of more that 2 nodes

## 7.4. The Algorithm

### 7.4.1. House Keeping stuff

- make sure the tree is rooted
- ensure that all nodes are `uniquely indexed` in some way so that we can reference them later
  - one easy way to index each node is by assigning each node a unique id between $[0, n-1]$

### 7.4.2. Eulerian Tour

- what's an eulerian tour? it's a path that visits every edge in a graph exactly once
- the eulerian tour method begins by finding an eulerian tour of the edges in a rooted tree
- rather than doing the euler tour 