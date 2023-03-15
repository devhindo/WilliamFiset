# Shortest Path

[video](https://youtu.be/oDqjPvD54Ss)

## Table of Contents

- [Introduction](#introduction)
- [The process](#the-process)

## Introduction

- The Breadth first search is another fundamental search algorithm used to explore nodes and edges of a graph. It runs with a time compexity of $O(V+E)$ where $V$ is the number of vertices and $E$ is the number of edges.
- It's often used as a building block in other algorithms.
- It's useful for finding the shortest path on unweighted graphs.

## The process

- A BFS starts at some arbitrary node of a graph and explores the neighbour nodes first, before moving to the next level neighbours in a layer fashion.
- It does that by maintaining a queue of nodes to visit.
- This is done using a queue data structure to track which node to visit next. Upon reaching a new node the algorithm adds it to structure works just like a real world queue.

[BFS code](./BFS.cpp)
