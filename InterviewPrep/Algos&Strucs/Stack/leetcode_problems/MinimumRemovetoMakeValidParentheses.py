# https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution(object):
    def minRemoveToMakeValid(self, s):
        helper_stack = []
        ret = ""
        real_ret = ""
        for el in s:
            if el == '(':
                helper_stack.append(1)
                ret += el
            elif el == ')':
                if helper_stack:
                    helper_stack.pop()
                    ret += el
                else:
                    pass
            else:
                ret += el

        helper_stack = []
        for el in ret[::-1]:
            if el == ')':
                helper_stack.append(1)
                real_ret += el
            elif el == '(':
                if helper_stack:
                    helper_stack.pop()
                    real_ret += el
                else:
                    pass
            else:
                real_ret += el
        return real_ret[::-1]