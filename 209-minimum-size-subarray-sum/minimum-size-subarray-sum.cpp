class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int sum = 0;
        int minCT=n+1;

        for (int i = 0; i < n; i++) {
             sum += nums[i];
            while (sum >= target) {
                minCT = min(minCT, i-p+1);
                sum -= nums[p];
                p++;
            } 
        }
        return (minCT==n+1)?0:minCT;
    }
};