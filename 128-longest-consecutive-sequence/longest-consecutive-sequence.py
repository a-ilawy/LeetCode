class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0: return 0
        numSet = set(nums)
        longest = 0
        left=[]
        right=[]
        for num in numSet:
            if (num - 1) not in numSet:
                left.append(num)
            if (num + 1) not in numSet:
                right.append(num)
        borders = left + right
        borders.sort()
        k=0
        longest = 0
        for n in range(0,len(borders)-1,2):
            longest = max(borders[n+1]- borders[n],longest)
        print(borders)
       
        return longest+1