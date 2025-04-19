class Solution:
    def maxArea(self, heights: List[int]) -> int:
        if 0 in heights and len(heights)==2:
            return 0
        left = 0
        right= len(heights)-1
        maximumAmountOfWater=1
        while left < right:
            w = abs(right - left)
            h = min(heights[right],heights[left])
            maximumAmountOfWater = max(h*w,maximumAmountOfWater)
            if heights[left] < heights[right]:
                left +=1
            else: right -=1
        return maximumAmountOfWater