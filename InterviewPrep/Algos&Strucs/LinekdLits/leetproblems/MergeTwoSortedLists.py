# https://leetcode.com/problems/merge-two-sorted-lists/description/

# Moje resenje 

class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1
        if not list1 and not list2:
            return None

        rethead = ListNode()
        if list1.val < list2.val:
            rethead.val = list1.val
            list1 = list1.next
        else:
            rethead.val = list2.val
            list2 = list2.next
        
        cur = rethead

        while list1 or list2:
            if list1 and (not list2 or list1.val < list2.val):
                cur.next = ListNode(list1.val)
                cur = cur.next
                list1 = list1.next
            elif list2 and (not list1 or list2.val <= list1.val):
                cur.next = ListNode(list2.val)
                cur = cur.next
                list2 = list2.next

        return rethead