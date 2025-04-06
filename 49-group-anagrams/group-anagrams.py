class Solution:

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = {}
        for st in strs:
            strsKey = ''.join(sorted(st))
            if strsKey not in result:
                 result[strsKey] = []
            result[strsKey].append(st)
        return list(result.values())
        