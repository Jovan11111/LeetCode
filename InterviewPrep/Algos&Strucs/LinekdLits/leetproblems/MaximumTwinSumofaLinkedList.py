# https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next 

# Moje resenje
class Solution(object):
    def pairSum(self, head):
        
        n = 0
        cur = head
        ret = 0
        while cur:
            cur = cur.next
            n += 1
        
        helper = []
        for _ in range(n/2):
            helper.append(head.val)
            head = head.next

        for i in range(n/2):
            ret = max(ret, head.val + helper[-1-i])
            head = head.next
        
        return ret