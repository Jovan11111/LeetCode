# OverView
- Tree is a hiararchical dat strcture that represents a set of nodes connected by edges.
- Tree is not linear
- Node is a single unit in a tree that contains data
- Root is the top node in a tree
- Parent is the node that is above the target node
- Child is the node that is under the target node
- Leaf is a node with no children
- Heihgt is the longest path from root to leaf
- Degree is a number of children a node has
# Usage
- Used to represent hiararchical relationships (in file systems, the files are leafs, dirs are nodes, and the root is the root dir)
- Used for structures where searching is often done
- In compiler design, the parser makes a Syntax tree to analyze the code (where keywords are leafs, and statements are nodes)
# Traversal Algos
```py
# Class for a tree node used in the algos
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Note: This is done for binary trees, it makes sense on how the n-ary trees would look like for other, but not for inorder. N-ary trees dont have inorder.

# First it visits the node that is looked at, then it visits the left node, then it visits the right node. It checks the target node PRE anything else
def preorderRecursive(root):
    if root: # if the node exists
        print(root.val)
        preorderRecursive(root.left)
        preorderRecursive(root.right)

    
# First it visits the left node, then the target node, then the right node. It checks the nodes INorder from left to right
def inorderRecursive(root):
    if root:
        inorderRecursive(root.left)
        print(root.val)
        inorderRecursive(root.right)

# First it checks the left node, then the right node, and then the target node. it checks the target node POST anything else
def postorderRecursive(root):
    if root:
        postorderRecursive(root.left)
        postorderRecursive(root.right)
        print(root.val)

# It uses a stack instead of recursion
def preorderIterative(root):
    if not root:
        return
    stack = []
    stack.append(root)
    while stack:
        node = stack.pop()
        print(node.val)
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

# It uses a stack instead of recursion
def inrderIterative(root):
    stack = []
    cur = root
    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        print(cur.val)
        cur = cur.right

# It uses a stack instead of recursion
def postorderIterative():
    if not root:
        return
    stack = []
    last_visited = None
    cur = root
    while cur or stack:
        if cur:
            stack.append(cur)
            cur = cur.left
        else:
            peek = stack.peek()
            if peek.right and last_visited != peek.right:
                cur = cur.right
            else:
                print(peek.val)
                last_visited = stack.pop()

```

# Importand types of trees
## General tree
## Binary tree
## Full binary tree
## Perfect binary tree
## Complete binary tree
## Balanced binary tree
## BST
## AVL
## Red black tree
## B-Tree
## B+ Tree
## Trie
## Heap
## Suffix Tree