# 3. Rooting a tree

[video](https://youtu.be/2FFq2_je7Lg?si=z3xR3zgM0LzonjWC)

## 3.1. Intro

- how to root a tree?
- this is one of those very basic fundemental transformations that's handy to have in your toolkit, in case you want to or need to work with a rooted tree.

## 3.2. How do we root a tree

- the motivation of rooting a tree is that often it can help to add structure and simplify the problem you are trying to solve.
- rooting a tree enables you to easily perform recursive algorithms.
- it also transforms the tree to have directed edges instead of undirected edges which are generally easier to work with.
- conceptually, rooting a tree is like `picking up` the tree by a specific node and having all the edges point downwards.
- you can root a tree using any of its nodes. however, be cautious because not every node you select will result in a well-balanced tree
and if that's your objective, you need to be a little more selective.
- In some situations, it's also useful to have a reference to the parent node in order to be able to walk up the tree.

## 3.3. Example on how to root a tree

- one of the best ways to do it is through a dpeth first search through the original tree and to create the rooted tree during the traversal.
- the algorithm starts on the designated root node.
- from the root node, begin the depth first search and add nodes to the rooted tree as the algorithm encounters them.

## 3.4. Code

```python

# Tree node object
class Node:

    # unique integer id to identify this node
    int id

    # pointer to parent Node reference
    # only the root node has a null parent node reference
    Node parent 

    # list of pointers to child Nodes.
    Node[] children

    def __init__(self, id, parent, children):
        self.id = id
        self.parent = parent
        self.children = children
# algorithm to root a tree

# g is the graph/tree represented as adjacency list with undirected edges
# it there's an edge between (u, v) there's also an edge between (v, u).
# rootId is the id of the node to root the tree from.

def rootTree(g, rootId=0):
    root = Node(rootId, None, [])
    return buildTree(g, root, None)

# build tree recursively depth first.
def build Tree(g, node, parent):
    # loop over all the nodes of current node
    # which will be the children of the current node
    for childId in g[node.id]:
        # because edges are undirected in the original tree we need to avoid the situation where we go back to the parent node
        if not parent and childId == parent.id:
            continue
        child = Node(childId, node, [])
        node.children.append(child)
        buildTree(g, child, node)
    return node
```
