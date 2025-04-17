class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        STmap = {}
        for i in range(len(s)):
            STmap[s[i]] = 1+STmap.get(s[i],0)
            STmap[t[i]] = STmap.get(t[i],0) - 1
        for m in STmap:
            if STmap.get(m,0):
                return False
        return True
        