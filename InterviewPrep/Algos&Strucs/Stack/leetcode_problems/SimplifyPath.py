# https://leetcode.com/problems/simplify-path/description/

class Solution(object):
    def simplifyPath(self, path):
        helper = path.split('/')
        ret = ["/"]
        for el in helper:
            if el == "..":
                if len(ret) != 1:
                    ret.pop()
                if len(ret) != 1:
                    ret.pop()
            else:
                if el and el !=".":
                    ret.append(el)
                    ret.append("/")
        if len(ret) != 1:
            ret.pop()
        return "".join(ret)
        