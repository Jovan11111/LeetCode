# https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next 

# Moje resenje
class Solution(object):
    def deleteDuplicates(self, head):
        if not head:
            return None
        cur = head
        prev = head

        while cur:
            if cur.val == prev.val:
                cur = cur.next
            else:
                prev.next = cur
                prev = cur
        prev.next = None      
        return head