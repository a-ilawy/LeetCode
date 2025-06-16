class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minNum = nums[0];
        int res=0;
        for(int i=0;i<n;i++){
           if(minNum >= nums[i]){
            minNum = nums[i];
           }else{
            res = max(res, nums[i]-minNum);
           }
        }
      
        return res<=0?-1:res;
    }
};