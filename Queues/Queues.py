from collections import deque


class QueueArray:
    def __init__(self, cap):
        self.cap = cap
        self.queue = [None] * cap
        self.front = 0
        self.rear = -1
        self.size = 0

    def is_full(self):
        return self.cap == self.size
    
    def is_empty(self):
        return self.size == 0
    
    def size(self):
        return self.size
    
    def enqueue(self, data):
        if self.is_full():
            print("Queue full")
            return
        self.rear = (self.rear + 1) % self.cap
        self.queue[self.rear] = data
        self.size += 1
    
    def dequeue(self):
        if self.is_empty():
            print("Queue empty")
            return
        
        data = self.queue[self.front]
        self.queue[self.front] = None
        self.front = (self.front + 1) % self.cap
        self.size -= 1
        return data
    
    def peek(self):
        if self.is_empty():
            print("Queue empty")
            return
        return self.queue[self.front]

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class QueueLinkedList:
    def __init__(self):
        self.front = self.rear = None
    
    def is_empty(self):
        return self.front is None
    
    def enqueue(self, data):
        new_node = Node(data)
        if self.rear is None:
            self.rear = self.front = new_node
            return
        self.rear.next = new_node
        self.rear = new_node

    def dequeue(self):
        if self.is_empty():
            print("Queue empty")
            return
        data = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        return data
    
    def peek(self):
        if self.is_empty():
            print("Queue empty")
            return
        return self.front.data
    

class StackUsingQueues:
    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, val):
        self.q2.append(val)
        while self.q1:
            self.q2.append(self.q1.popleft())
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if not self.q1:
            print("Stack empty")
            return
        return self.q1.popleft()

    def peek(self):
        if not self.q1:
            print("Stack empty")
            return
        return self.q1[0]

    def is_empty(self):
        return not self.q1