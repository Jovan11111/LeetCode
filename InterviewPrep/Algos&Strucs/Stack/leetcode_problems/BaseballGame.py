# https://leetcode.com/problems/baseball-game/

class Solution(object):
    def calPoints(self, operations):
        stack = []
        for el in operations:
            if el == "C":
                stack.pop()
            elif el == "D":
                x = stack.pop()
                stack.append(x)
                stack.append(2*x)
            elif el == "+":
                x = stack.pop()
                y = stack.pop()
                stack.append(y)
                stack.append(x)
                stack.append(x+y)
            else:
                stack.append(int(el))
        return(sum(stack))