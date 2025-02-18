# https://leetcode.com/problems/linked-list-cycle/

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None 

# Moje resenje
class Solution(object):
    def hasCycle(self, head):
        fast = head
        slow = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                return True
        return False