# 1. Introduction to tree algorithms

[video](https://youtu.be/1XC3p2zBK34?si=GGwf0NxaRnWK0VCW)

## 1.1. Introduction

`-- what's a tree? --`

- How we computationally store and represent trees.
- a Tree is an undirected graph with no cycles.
- a Tree cannot have cycles because if it did, it would be a graph.

- There is an easier way to check if a tree is a graph or not: each tree has exactly N nodes and N-1 edges.

- Examples where you can encounter a tree in real-life:
  - computer file system, which consists of directories and subdirectories and files which is inherently a tree structure.
  - social heirarchy, where you have a CEO and then you have managers and then you have employees and so on.
  - decompose source code and mathematical expressions which called abstract syntax trees for easier evaluation.
  - every web page due to HTML nested tags is a tree.
  - In game theory to model decisions, like the famous prisoner's dilemma problem.

## 1.2.  Storing undirected trees

`-- how do we represent an undirected tree? --`

- first you should label all your nodes by numbers from $[0, n)$

- **Method 1: edge list storage representation:**
  - simply a list of undirected edges indicating which 2 nodes are connected.
    - data structure: `List<Pair<Integer, Integer>>`
    -- ex: `[(1,2), (2,3), (2,4), (3,5), (4,6)]`
  - upside: super fast to iterate over and cheap to store
  - downside: storing a tree as a list lacks the structure to do efficiently query all the neighbors of a node. This is why the adjacency list representation is used.

- **Method 2: adjacency list representation:**
  - you store a mapping between a node and all its neighbors.
    -- data structure: `Map<Integer, List<Integer>>`
    -- ex: `{1: [2], 2: [1, 3, 4], 3: [2, 5], 4: [2, 6], 5: [3], 6: [4]}`

- **Method 3: adjacency matrix representation:**
  - size: $n \times n$
  - having a one in particular cell meaning that there is an edge between the two nodes.
  - however, in practice, avoid storinga tree as an adjacency matrix! It's a huge waste of space to use $O(n^2)$ space and only use $O(2(n-1))$ of the matrix cells. Meaning that: $O(n^2)$ space is used to store $O(n)$ information.

## 1.3. Rooted Trees

- It's trees that has a special node called the root node.
- most rooted trees have directed edges which points away from the root node. It's also possible for the edges to point towards the root node but it's less common.
- general speaking rooted trees are far easier to work with than undirected trees. because of their well defined structure which allows for easy recursive algorithm implementations.

## 1.4. Binary Trees (BT)

- A binary tree is a rooted tree where each node has at most two child nodes.
- you don't often see binary trees manifest their self in the real world, For the most part binary trees are artificially and integrated as part of a data structure by computer scientists to garantee efficient in searching, removing and accessing data, like (Binary Search Tree, Heap, Trie, etc.)

## 1.5. Binary Search Trees (BST)

- binary trees that satisfy the `binary search trees` invariant. which states that for every node $x$.
    $x.left.value \leq x.value \leq x.right.value$
- this property enables you to quickly search for a value in the tree.
- It's often useful to require unique values in a BST, to not have duplicate values. so you might change the invariant to:
    $x.left.value < x.value < x.right.value$

## 1.6 Storing Rooted Trees

- rooted trees are most maturally defined recursively in a top-down fashion.
- in practice, you always maintain a pointer reference to the root node so that you can access the tree and its contents.
- then each node also has access to a list of all its children nodes.
- sometimes it's also useful to maintain a pointer to a node's parent node effectively making edges bidirectional. In case you want to traverse up the tree.
- However maintaing a pointer to a node's parent is not always necessary because you can access a node's parent on a recursive function's callback as you pop frames off the stack.

## 1.7 storing binary tree as a `flattened array`

- `flattened array` is an array where you store the tree in a breadth first search order.
- In a flattened array representation each node has an assigned index position based on where it is in the tree in a breadth first search order.
- here, the tree is a actually an array, the diagrams are just a visual representation of what the tree looks like
- nodes which aren't currently in the tree are represented by a null value.
- the root is always at index 0, so you always know where the starting node is.
- another advantage for this representation is that the child nodes of node $i$ can be accessed relative to the postion of $i$ at: index $2i + 1$ and $2i + 2$. and the parent node can be found at index $\lfloor \frac{i-1}{2} \rfloor$.
