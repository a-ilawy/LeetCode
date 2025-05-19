class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n+1);
        p[0]=1;
        vector<int> s(n+1);
        s[n] = 1;

        for(int i=0;i<n;i++){
            p[i+1] =  p[i] * nums[i];
        }

        for(int i=n-1;i>=0;i--){
           s[i] = s[i+1] * nums[i];
        }

        for(int i=0;i<n;i++){
          nums[i] = p[i] * s[i+1];
        }

        for(int i=0;i<s.size();i++){
           cout<<s[i]<<",";
        }

        return nums;
    }
};