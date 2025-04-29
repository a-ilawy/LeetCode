class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        res=[]
        ct=0
        for i in nums:

            if i in res:
                ct= res.count(i)
            if ct<2:
                res.append(i)
            else: ct=0

           
           
            print(f"ct: {ct} || i: {i}")
        print(res)
        for i in range(len(res)):
            nums[i] = res[i]
        return len(res)
        