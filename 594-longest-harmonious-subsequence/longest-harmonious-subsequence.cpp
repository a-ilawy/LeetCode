class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (auto i: nums) cout << i << ' ';
        int l = 0;
        int maxLength = 0;

        for(int r =0; r<n;r++){
            while( nums[r] - nums[l] > 1 ){
                l++;
            }
            if( nums[r] - nums[l] == 1){
                maxLength = max(maxLength, r-l+1);
            }
            
        }
        return maxLength;
    }
};