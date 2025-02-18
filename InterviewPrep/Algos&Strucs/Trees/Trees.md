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
![image](https://github.com/user-attachments/assets/5306d5f8-21a7-4cef-bc54-6ba569a731cb)
- Any node can have any number of children. This tree is not used often.
## Binary tree
![image](https://github.com/user-attachments/assets/05a557dc-a4da-4aca-b0d3-72f533db1144)
- Binary tree can have a maximum of 2 children per node. It is a n-ary tree with n = 2.
- Binary tree is a tree which has 2 children, and both children are binary trees
## Full binary tree
![image](https://github.com/user-attachments/assets/8ec98e71-76e3-47bb-b57a-1b05760f227d)
- Full binary tree is a tree in which nodes can either have 2 children, or no children. 
## Perfect binary tree
![image](https://github.com/user-attachments/assets/bda4dfab-9637-4bd5-9b59-4732f7c172b8)
- Perfect binary tree is a tree where all nodes either have 2 children, or no children, and also left and right child of perfect binary tree have the same depth. The perfect binary tree is completly full, adding another node would start the new level
- Perfect binary tree is also a full tree
## Complete binary tree
![image](https://github.com/user-attachments/assets/4d9a9c0f-2dc1-4186-bbef-caf0641e349f)
- Complete binary tree is a perfect binary tree for all levels except for the last one. The last level is filled from left to right, and doesnt have to be perfect. When adding a new node, its added on the next spot where is should go
## Balanced binary tree
![image](https://github.com/user-attachments/assets/9c49f8f0-13a5-4b82-8802-59fdee954c01)
- Its a tree where the depth of left and right child doesnt differ more then one
- Its a tree where no leaf is much farther away from the root then any other leaf. 
## BST
![image](https://github.com/user-attachments/assets/baa78e4d-ad63-404a-9c49-b1d04550c467)
- BST is a binary search tree. Its nodes have values where the following rule is applied: All nodes that are part of the left subtree have values bigger then the value in target node, and all the nodes that a part of the right subtree have values smaller then the valud in target node.
- This tree is very usefull in cases where searching and looking if element exists is common, because it can find an element in log2n time.
- Worst case scenario for this tree is if the values that are inserted in a tree are sorted. Then the tree is actually just a linked list
```py
def BSTsearchRecursive(root, key):
    if not root or root.key == key:
        return root

    if root.val < key:
        return BSTsearchRecursive(root.right, key)
    else:
        return BSTsearchRecursive(root.left, key)

def BSTseachIterative(root, key):
    cur = root
    while cur:
        if cur.val == key:
            return True
        elif cur.val < key:
            cur = cur.right
        else:
            cur = cur.left
    return False
```
- Insertion in this tree is similar to search. Instead of only looking for a key, the algorithm first looks if key is in a tree, and if it doesnt find it, it already knows where it should go, so it inserts it.
```
def BSTinsert(root, key):
    cur = root

    while True:
        if cur.val == key:
            return False # Key already exists, it is not inserted
        elif key < cur.val:
            if cur.left:
                cur = cur.left
            else:
                break
        else:
            if cur.right:
                cur = cur.right
            else:
                break

    if cur.val < key:
        cur.left = Node(key)
    else:
        cur.right = Node(key)
```
## AVL
## Red black tree
- RBT is a self ballancing binary tree that can have black and red nodes
- RBT is better then BST because it is self balanced
- When tree is changed, the nodes are repainted.
- This tree guarantees searching in O(log n) time
- The leaf nodes of RBT are NIL nodes, and they do not contain keys. Only internal nodes have keys
- Every node is either red or black, and all NIL nodes are black.
- Red node cant have a red child
- Every path from a given node to all its NIL nodes always goes through the samo number of black nodes. this means that if some node only has one child, the child must be RED
- Root is always black
- Search, deletion and insertion all start by standard BST operations, but then after insertion and deletion, the tree must be recolored and reorganized so it stays balanced 

## B-Tree
## B+ Tree
## Trie
## Heap
- Heap is a special tree, that satisifes the followin:
1. If its a max heap, it has the biggest element in the root, and all other elements are smaller then the root element. The same applies for its children. The left childs subtree is a subtree where the left child of root is the biggest element in that subtree, and the same applies for right
2. If its a min heap, then the smallest element is in the root, and everything else is like a max heap but reversed
- Heaps are usually stored in arrays, so if a node is at index i, its children are at indexes 2\*i+1 and 2\*i+2, and its parent is at (i-1)//2
- Heap is very usefull in heap sort algorithm, where to sort an element you make a heap, and then insert all elements in the heap, and then take them out of the heap one by one. They will be sorted
- Heaps are used to implement priority queues, where the element with the biggest priority will always be at the top of the heap
- Insertion in a heap involves inserting an element at the bottom of the heap (appending to the array) and then placing it higher and higher to the place it actually should go to. This is called hearifying up..
```py
def insertMinHeap(heap, element):
    heap.append(element)
    i = len(heap)-1
    while i > 0:
        parent = (i - 1) // 2
        if heap[i] <= heap[parent]: # should be >= in max heaps
            break
        heap[i], heap[parent] = heap[parent], heap[i]
        i = parent
```
![image](https://github.com/user-attachments/assets/ac44fbe2-fc88-4b40-8293-68b68a195662)

- To delete the biggest/smallest elemnt from the heap, you need to take the first element and remove it, and then move the new first element down until its in a correct place. This is called heapifying down
```
def delete_min(heap):
    if len(heap) == 0:
        return None
    if len(heap) == 1:
        return heap.pop()
    root = heap[0]
    heap[0] = heap.pop()

    heapify_down(heap, 0)

    return root

def heapify_down(heap, i):
    size = len(heap)
    smallest = i
    left = 2*i+1
    right = 2*i+2
    if left < size and heap[left] < heap[smallest]:
        smallest = left
    if right < size and heap[right] < heap[smallest]:
        smallest = right
    if smallest != i:
        heap[i], heap[smallest] = heap[smallest], heap[i]
        heapify_down(heap, smallest)
```
## Suffix Tree

# Storing a tree
```py
class TreeNode:
    def __init__(self, value = 0):
        self.value = value
        self.children = []
        # for binary trees it would be:
        # self.left = None
        # self.right = None
```
- Binary tree can be stored in an array like this:
![image](https://github.com/user-attachments/assets/d353d0e5-7a95-4a53-8b1f-58148f766353)
- A tree can be stored as a dict of lists, where key is the node, and in the list are its children
![image](https://github.com/user-attachments/assets/28742034-4a39-40c0-9706-99d5eb0949f2)

