class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        setNum =[]
        ct=0
        for i in nums:
            if i not in setNum:
                setNum.append(i)
                ct+=1
        print(f"res: {setNum}")
        for i in range(len(setNum)):
            nums[i] = setNum[i]
        return ct