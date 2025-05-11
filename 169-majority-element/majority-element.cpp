class Solution {
public:
    int majorityElement(vector<int>& nums) {
       if (nums.size()==1){return nums[0];}
        std::unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int maxAppear = 0;
        int num = 0;
        for (const auto& pair : freq) {
            if (pair.second > 1) {
                if (maxAppear < pair.second) {
                    maxAppear = pair.second;
                    num = pair.first;
                }
            }
        }
        return num;
    }
};