# https://leetcode.com/problems/merge-nodes-in-between-zeros/

class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next


# Moje resenje
class Solution(object):
    def mergeNodes(self, head):
        head = head.next
        cur_sum = 0
        cur = head
        next_zero = head
        while True:
            while next_zero.val != 0:
                cur_sum += next_zero.val
                next_zero = next_zero.next
            next_zero = next_zero.next
            if next_zero:
                cur.next = next_zero
                cur.val = cur_sum
                cur_sum = 0
                cur = next_zero
            else:
                cur.next = None
                cur.val = cur_sum
                break
        return head
        