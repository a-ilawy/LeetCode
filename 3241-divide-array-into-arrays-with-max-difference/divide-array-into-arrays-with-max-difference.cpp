class Solution {
public:
    // [1,1,3,3,4,5,7,8,9]
    // [2,2,2,2,4,5] -> sorted
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0; i< nums.size();i+=3){
            if(nums[i+2]-nums[i] > k)return {};
            res.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return res;
    }
};