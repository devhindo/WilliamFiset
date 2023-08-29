# 2. Beginner tree algorithms

[video](https://youtu.be/0qgaIMqOEVs?si=tqoOqvu0xeplXP1l)

## 2.1. Intro

- simple tree algorithms that involve recursion.
- solving 2 problems, which you may encounter as a warmup in interviews.

## 2.2 Problem 1: leaf node sum

- what is the sum of all the leaf node values in a tree?
  - note that it's not a binary tree, so a node might have more than 2 childrens.

### solution

- all we need to do is perform a tree traversal and sum up the values of the leaf nodes as we encounter them during the traversal.
- 2 popular traversal algorithms are DFS and BFS.
- on trees DFS is usually preferred because it is easier to implement using recursion.
- we will use DFS to solve this problem.

```python
    def sum(node):

        if not node:
            return 0

        if len(node.children) == 0:
            return node.val
        
        total = 0
        for child in node.children:
            total += sum(child)
        
        return total
    
    totalSum = sum(root)
```

#### similar problems

- [404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/) `sum up only left leaves`

## 2.3 Problem 2: Tree Height

- I thought about explaining this problem as a tree not a binary tree as mentioned in the video and you can find the explanation below and after you understand it you can try solving the binary tree version by yourself found [here](https://leetcode.com/problems/maximum-depth-of-binary-tree/).

- It's a classic problem in computer science to find the height of a tree.
- the height of a tree is defined by the number of edges from the root node to the lowest leaf node.
- we are going to break it down and to find a new function called $h(x)$ which returns the height of the sub-tree rooted at node $x$.
- this new function allows us to start thinking not only about the height of the tree as a whole but also the height of the sub-tree within our tree which are going to help us find the overall height
- by themselves, leaf nodes don't have any children, so they don't add any additional height to the tree, so we conclude that as a base case:
  - $h(x) = 0$ if $x$ is a leaf node.
- now, assuming node $x$ is not a leaf node, we're able to formulate a recurrence relation for the height:
  - $h(x) = 1 + max(h(c_1), h(c_2), ..., h(c_n))$ where $c_1, c_2, ..., c_n$ are the children of node $x$.

### code

#### Tree solution code

```python

    def treeHeight(node):

        # handle empty tree case
        if not node:
            return -1

        # identify leaf nodes and return zero
        if len(node.children) == 0:
            return 0
        
        return max([treeHeight(child) for child in node.children]) + 1
        
```

#### Binary Tree solution code

```python

    def binaryTreeHeight(node):

        # handle empty tree case
        if not node:
            return -1

        # identify leaf nodes and return zero
        if not node.left and not node.right:
            return 0
        
        return max(binaryTreeHeight(node.left), binaryTreeHeight(node.right)) + 1
        
```

- Question: Do you think if we remove the identify leaf nodes and return zero part from the code, will it still work?
- Answer: Yes, it will still work because the max function will return -1 if the node is a leaf node and the height of the tree will be -1 + 1 = 0.
- It works because the base case has apodpted a new meaning, instead of the base case checking for leaf nodes, it's now checking if a node is NULL and returning -1.
- now returning -1 is not only for handling the empty tree case but also to help in correcting for the right tree height.
- if our new base case now checking for NULL nodes instead of leaf nodes then our tree is one unit taller, so we need to correct that.
- algorithm approach:
  - once we reach a NULL node return -1.
  - on the recursive callback, remember that we always add +1 with our reccurence.

- In practice, if you are designing a datastructure where the tree height is important, you can dinamecly keep track of the height as you create the tree and insert nodes instead of fully computing the height as we did, but ofc that is always doeble.

### Similar problems

- [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

## 2.5 Additional problems

- [129. Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
