class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        myMap = {}
        for i in range(len(numbers)):
            if numbers[i] in myMap:
                return [myMap[numbers[i]]+1,i+1]
            myMap[target-numbers[i]] = i