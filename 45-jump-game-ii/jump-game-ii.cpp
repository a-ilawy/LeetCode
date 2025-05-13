class Solution {
public:
    int jump(vector<int>& nums) {

        int jumpSteps = 0;
        int goalIndex = nums.size() - 1;

        while (goalIndex > 0) {
            for (int i = 0; i < goalIndex; ++i) {
                if (i + nums[i] >= goalIndex) {
                    goalIndex = i;
                    jumpSteps++;
                    break;
                }
            }
        }

        return jumpSteps;
    }
};