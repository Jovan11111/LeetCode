#https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution(object):
    def preorderTraversal(self, root):
        ret = []
        if not root:
            return []
        stack = [root]
        while stack:
            cur = stack.pop()
            ret.append(cur.val)
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
        
        return ret