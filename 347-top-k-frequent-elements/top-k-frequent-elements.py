class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        iCount = {}
        vCount = [[] for i in range(len(nums)+1)]
    
        for n in nums:
            iCount[n]= 1 + iCount.get(n,0)
        for key,val in iCount.items():
            vCount[val].append(key)
        res = []
        for i in range(len(vCount)-1,0,-1):
            for n in vCount[i]:
                res.append(n)
                if(len(res)==k): return res
        print(vCount)
