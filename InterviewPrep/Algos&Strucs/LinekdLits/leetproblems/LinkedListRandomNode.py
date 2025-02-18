# https://leetcode.com/problems/linked-list-random-node/

import random

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next 

class Solution(object):
    def __init__(self, head):
        self.helper = []
        while head:
            self.helper.append(head.val)
            head = head.next
        

    def getRandom(self):
        return self.helper[random.randint(0, len(self.helper)-1)]