class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right=height.size()-1;
        int maximumAmountOfWater = 0;
        int h=0, w=0;
        while(left < right){
            w = abs(left - right);
            h = min(height[left], height[right]);

            maximumAmountOfWater = max(maximumAmountOfWater, h*w);

            while(left < right && height[left] <=h) left++;
            while(left < right && height[right] <=h) right--;
        }
        return maximumAmountOfWater;
    }
};