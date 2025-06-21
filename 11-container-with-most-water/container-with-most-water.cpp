class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right=height.size()-1;
        int maximumAmountOfWater = 0;

        while(left < right){
            int w = abs(left - right);
            int h = min(height[left], height[right]);

            maximumAmountOfWater = max(maximumAmountOfWater, h*w);

            while(left < right && height[left] <=h) left++;
            while(left < right && height[right] <=h) right--;
        }
        return maximumAmountOfWater;
    }
};