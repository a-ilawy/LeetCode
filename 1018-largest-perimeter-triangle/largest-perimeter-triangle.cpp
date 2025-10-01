class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int cnt=0;
        for(int i=2; i<nums.size(); i++){
            int c = nums[i];
            int b = nums[i-1];
            int a = nums[i-2];

            if( a < (b+c)){
                    // cout<<a<<" "<<b<<" "<<c<<endl;
                    return a+b+c;
            }
        }
        return 0;
    }
};
// 10 2 1 1