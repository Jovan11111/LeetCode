# OverView
- Linear data structure
- Saves the value and the pointer to the next value
- Not saved in continous memory spaces
- **Singly Linked List** - Node points to the next node
- **Doubly linked list** - Node points to the next node, and also to the previous node
- **Circular linked list** - Last node point to the first node, there is a cycle
```py
class Node:
    data = None
    next = None
    def __init(self, data):
        self.data = data
        self.next = None
        # self.prev = None - For double linked lists
```

## Insertion
```py
def insert_beggining(head, data):
    new_node = Node(data) # Create a new node
    new_node.next = head # Make the next of the new node be the current first node
    # head.prev = new_node - For double linked lists
    head = new_node # Move the pointer for first node to the new node
    return head

def insert_end(head, data):
    new_node = Node(data) # Create a new node
    if not head: # If list empty, return new node
        return new_node
    cur = head
    while cur.next: # traverse through the list 
        cur = cur.next
    cur.next = new_node # Last node now point to the new node
    # new_node.prev = cur - For double linked lists
    return head

def insert_after_node(target, data):
    if not target: # If target doesnt exist return
        return
    new_node = Node(data) # Create a new node
    new_node.next = target.next # Next of the new node is what was next for the target
    target.next = new_node # Next for the target is a new node
```

## Deletion
```py
def delete_beggining(head):
    if not head:
        return Node
    head = head.next # Just move the head
    return head

def delete_end(head):
    if not head or not head.next:
        return None
    cur = head
    while cur.next.next: # Traverse to the second to last element of the list
        cur = cur.next
    cur.next = None # Set the next of second to last element to None, now it is the last
    return head

def delete_special(head, key):
    if not head:
        return None
    if head.data == key: # If the head has the key, return the head
        return head.next
    cur = head
    while cur.next and cur.next.data != key: # traverse until the end or until the next node had the key
        cur = cur.next
    if cur.next: # If the key is found, skip the node that had the key
        cur.next = cur.next.next
    return head
```
 
## Usage
- When there is dynamic memory, heap memory
- When you need to use the list, and you need to insert and delete element often
- When you need to utilize memory
- Do not use then you need to access element often, because you can access elements only sequentially
- Do not use if there is not much memory, bcos they use more memory then arrays
**Irl usage**:
- File allocation table (FAT) uses linked lists to manage clusters on the disc
- stacks, queues, graphs, can be represented with linked lists
- next/previous buttons on user interfaces
## Basic Algos
```py
# Reversing a list
def reverse_list(head):
    prev = None
    cur = head
    while cur:
        next_node = cur.next
        cur.next = prev
        prev = cur
        cur = next_node
    return prev

# Slow/fast pointer
def detect_cycle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
```