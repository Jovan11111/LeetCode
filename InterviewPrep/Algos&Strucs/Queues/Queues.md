# Overview
- Linear data structure
- First in First Out structure, **FIFO**
- Its a *queue* of something. You insert something, it has to wait until everything before it is removed
- Operations:
    - Enqueue to add element at the end of the queue
    - Dequeue to remove element from the front of the queue
    - Peek to get the front, but dont remove it
    - IsEmpty to see if there are any elements in the queue
    - size to see how many elements are in the queue

## Usage
1. Scheduling algos - when processes need to enter something in order, they are put in a queue
2. BFS in graph is done using a queue
3. Spooling is done with a queue, when a process want to print something, it puts what it want to print in a queue
4. Managing requests on a server