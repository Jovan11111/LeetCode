# https://leetcode.com/problems/merge-in-between-linked-lists/

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Moje resenje 
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        cur = list1
        for _ in range(a - 1):
            cur = cur.next
        a_node = cur

        for _ in range(b - a + 2):
            cur = cur.next
        
        a_node.next = list2

        while list2.next:
            list2 = list2.next
        
        list2.next = cur

        return list1