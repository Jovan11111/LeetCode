class StackArray:
    def __init__(self, cap):
        self.cap = cap
        self.stack = [None] * cap
        self.top = -1

    def push(self, data):
        if self.top == self.cap - 1:
            print("Cant do it, stack is full")
            return
        self.top += 1
        self.stack[self.top] = data

    def pop(self):
        if self.top == -1:
            print("Cant do that, stack is empty")
            return
        data = self.stack[self.top]
        self.stack[self.top] = None
        top -= 1
        return data

    def peek(self):
        if self.top == -1:
            print("Cant do that, stack is empty")
            return
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1

    def size(self):
        return self.top + 1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None 
class StackList:
    def __init__(self):
        self.head = None
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def pop(self):
        if not self.head:
            print("Stack empty")
            return
        data = self.head.data
        self.head = self.head.next
        return data
    
    def peek(self):
        if not self.head:
            print("Stack empty")
            return
        return self.head.data
    
    def is_empty(self):
        return not self.head
    
    def size(self):
        ret = 0
        cur = self.head
        while cur:
            cur = cur.next
            ret += 1
        return ret   

class QueueUsingStacks:
    def __init__(self):
        self.s1 = []
        self.s2 = []
    
    def enqueue(self, val):
        self.s1.append(val)
    
    def dequeue(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            print("Queue empty")
        return self.s2.pop()
    
    def peek(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        if not self.s2:
            print("Queue empty")
        return self.s2[-1]
    
    def is_empty(self):
        return not self.s1 and not self.s2
    
    def size(self):
        return len(self.s1) + len(self.s2)
    
    
class Solutions:
    def sort_stack(stack):
        pass

    def valid_parens(s):
        pass

    def next_greater_element(arr):
        pass 