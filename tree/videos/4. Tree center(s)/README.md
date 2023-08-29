# 4. Tree center(s)

[video](https://youtu.be/nzF_9bjDzdc?si=MZQTL4p3Wq2y2Sy-)

## 4.1. explanation

- how to find the center of a tree?
- note that we are talking about undirected tree
- this is the sort of problem that you might encounter in a coding interview or a competitive programming contest.
- finding the center of a tree is a handy algorithm to know because you will see it from time to time in the subroutine of other algorithms and it's also a useful way of selecting the root node when you tryna root a tree which we talked about [here](../3.%20Rooting%20a%20tree/README.md).
- one thing to be aware of when finding the center of a tree is that there can be more than one center, either you run into the case where a tree that has a unique center which is nice or you run into a tree which has two centers, however there can't be more than two centers, do you know why?
- you will notice that the center is always the middle or middle two vertices along the longest path of a tree
- so the center of a tree is the middle vertex along the longest path
- if we select another longest path you will see that you end with the correct center node
- another approach to find the center or centers of a tree is to repeatedly remove the outer layer of leaf nodes. this proccess resembles that of peeling an onion, you start from the outside until you reach the center.
  - the first thing we going to do is first compute the degree of each node. that is the number of nodes it's connected to
  - you will notice that each of the leaf nodes has a degree of one, since leaf nodes can only be connected to one other node.
  - once we know where the leaf nodes are we can prune them and update the degree of their neighbors
  - after that repeat the same proccess: identify the leaf nodes and prune them and update degree values.
  - if you keep doing this you can eventually reach the center of the tree
  - you end when you're left with either one or two nodes. center or centers as explained before.

## 4.2. code

```python

# g = tree represented as an undirected graph (adjacency list)

def treeCenters(g):
    # n = number of nodes
    n = len(g)
    # degree = array of node degrees
    degree = [0] * n
    # leaves = the most recent layer of leaf nodes
    leaves = []
    # loop throught all nodes and compute the degree
    # counting the number of edges incident to each node
    for node in g:
        degree[node] = len(g[node])
        # if degree[node] == 0 means single node tree
        # if degree[node] == 1 means leaf node
        if degree[node] <= 1:
            leaves.append(node)
            # set degree to 0 so we don't proccess it again
            degree[node] = 0
    
    # the way we are going to know when we reach the center or centers is when we have proccessed all the nodes in the tree.
    # count will keep track of how many nodes we have proccessed so far
    # every iteration we will going to increment count by the number of leafs we found in the last layer
    count = len(leaves)
    while count < n:
        # newLeaves = next layer of leaf nodes
        newLeaves = []
        # loop through the current layer of leaf nodes
        for node in leaves:
            # for each neighbor of node
            for neighbor in g[node]:
                # decrement the degree
                degree[neighbor] -= 1
                # if neighbor degree == 1 that means it's now a leaf node
                if degree[neighbor] == 1:
                    # add it to the new layer
                    newLeaves.append(neighbor)
            # set degree to 0 to mark it as done
            degree[node] = 0
        # update count to be the number of nodes proccessed so far
        count += len(newLeaves)
        # the new layer of leaf nodes becomes the current layer and ignore the previous layer
        leaves = newLeaves
    # the remaining nodes are the centers of the tree
    return leaves
```
