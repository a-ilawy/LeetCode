class Solution {
public:
    int jump(vector<int>& nums) {
         if (nums.size() == 1) {
        return 0;
    }
    if (nums.size() == 2 && nums[0] >= 1) {
        return 1;
    }

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