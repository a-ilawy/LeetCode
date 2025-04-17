import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # get all only printable ASCII characters
        rS = re.findall(r'[a-zA-Z0-9]', s)    
        p=len(rS)-1
        for rs in rS:
            # print(f"{rs.lower()},  {rS[p].lower()}")
            if rs.lower()!=rS[p].lower(): return False
            p-=1
        return True