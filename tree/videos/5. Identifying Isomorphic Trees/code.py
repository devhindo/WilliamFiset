  # class difinition
class Node:
    """
        tree class
    """
    def __init__(self, val):
        self.val = val
        self.children = []

    parent = None
    children = []

    def add_undirected_edge()
        

def is_isomorphic(t1, t2):

    """
    Returns whether two trees are isomorphic
    parameters tree1 and tree2 are undirected trees
    sorted as adjacency lists
    """
    t1Centers = treeCenters(t1)
    t2Centers = treeCenters(t2) 

    t1_rooted = rootTree(t1, t1Centers[0])
    
    t1_encoded = encode(t1_rooted)

    for center in t2_centers


def encode(n: TreeNode):

    if not n:
        return ""
    
    code = []

    for c in n.children:
        code.append(encode(c))

    code.sort()

    serial = ""

    for c in code:
        serial += c
    

    
    return "(" + serial + ")"


def Tree_center(t):
    pass




