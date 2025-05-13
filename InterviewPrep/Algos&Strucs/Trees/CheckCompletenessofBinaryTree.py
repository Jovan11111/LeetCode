# https://leetcode.com/problems/check-completeness-of-a-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def isCompleteTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        queue = deque()
        queue.append(root)
        endOfTree = False

        while len(queue) > 0:
            node = queue.popleft()
            if endOfTree and (node.left or node.right):
                return False
            elif node.left and not node.right:
                endOfTree = True
                queue.append(node.left)
            elif node.right and not node.left:
                return False
            elif not node.right and not node.left and not endOfTree:
                endOfTree = True
            elif node.left and node.right:
                queue.append(node.left)
                queue.append(node.right)

        return True
