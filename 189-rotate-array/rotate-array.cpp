class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp=0;
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
         reverse(nums.begin()+k,nums.end());
        for(int i=0;i<n;i++){
            cout<<nums[i];
        }
    }
};