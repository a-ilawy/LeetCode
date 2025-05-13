class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpSteps=1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] >= jumpSteps){
                jumpSteps=1;
            }
            else{
                jumpSteps+=1;
            }
        }
        if(jumpSteps==1){
            return true;
        }
        return false;
    }
};