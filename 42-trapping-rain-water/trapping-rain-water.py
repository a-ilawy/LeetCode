class Solution:

    # def area (self,start:int,end:int,barStart:int, barEnd:int) -> int:
    #     w = abs(end - start)-1
    #     h = min(barStart,barEnd)
    #     print(f"start -> {start} || end -> {end} --||-- height -> {h} ")
    #     return h*w


    def trap(self, height: List[int]) -> int:
        # currEdg=[0,0] #[barIndex, barHeight]
        # totalArea=0
        # middleBarsH = 0
        # for i in range(len(height)):
        #     print(f"startBar -> {currEdg[1]} || endBar -> {height[i]}")
        #     if height[i]>=currEdg[1]:
                
        #         totalArea += self.area(currEdg[0],i, currEdg[1], height[i]) - middleBarsH
        #         currEdg[0] = i
        #         currEdg[1] = height[i]
        #         print(f"totalArea -> {totalArea}")
        #     else:
        #         print(f"startBar -> {currEdg[1]} || middleBar -> {height[i]}")
        #         middleBarsH += height[i]
        # return totalArea
            

        l_bar = r_bar = 0
        n = len(height)
        max_right = [0]*n
        max_left = [0]*n

        for i in range(n):
            j = -i - 1
            max_right[j] = r_bar
            max_left[i] = l_bar
            r_bar = max(r_bar, height[j])
            l_bar = max(l_bar, height[i])
        print(max_right)
        print(max_left)

        area=0
        for i in range(n):
            pot = min( max_right[i],max_left[i])
            area += max(0, pot - height[i])
        return area
            