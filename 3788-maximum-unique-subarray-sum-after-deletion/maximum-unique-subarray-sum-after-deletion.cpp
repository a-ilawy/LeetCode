class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int sum = 0;
        for (int val : unique) {
            if (val > 0) sum += val;
        }
        if(sum==0){
            sum=nums[0];
            for (int n : nums) {
                if (n > sum) sum = n;
            }
        }
        return sum;
    }
};