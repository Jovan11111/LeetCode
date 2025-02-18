# https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution(object):
    def flatten(self, head):
        cur = head
        while cur:
            if cur.child:
                ch1 = cur.child
                ch2 = ch1
                while ch2.next:
                    ch2 = ch2.next
                ch2.next = cur.next
                if cur.next:
                    cur.next.prev = ch2
                ch1.prev = cur
                cur.next = ch1
                cur.child = None

            cur = cur.next
        return head
        