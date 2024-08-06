class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1 

        while left < right:
            while not s[left].isalnum() and left < right:
                left += 1
            
            while not s[right].isalnum() and left < right:
                right -= 1
            
            if(s[left].lower() != s[right].lower()):
                return False

            left += 1
            right -= 1
        return True

"""
- Moje resenje:
- 2 pointera, jedan na pocetak jedan na kraj, i prblizavaju se i to je to
- Preskacu se oni koji nisu alnum, i proverava se da li su levi i desni isti, jednostavno
- Pravilno resenje:
- isto

"""
