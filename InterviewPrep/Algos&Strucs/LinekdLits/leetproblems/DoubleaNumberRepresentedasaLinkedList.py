# https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val 
        self.next = next

# Moje resenje
class Solution(object):
    def doubleIt(self, head):
        cur = head

        if head.val > 4:
            head = ListNode()
            head.next = cur
        
        while cur:
            cur.val *= 2
            cur = cur.next
        
        cur = head
        while cur.next:
            if cur.next.val > 9:
                cur.val += 1
                cur.next.val -= 10
            cur = cur.next
        return head
    