class Solution:

    def encode(self, strs: List[str]) -> str:
        if strs == [""]:
            return "/n"
        return '/n'.join(strs)

    def decode(self, s: str) -> List[str]:
        if not s:
            return []
        if s == "/n":
            return [""]
        return s.split('/n')