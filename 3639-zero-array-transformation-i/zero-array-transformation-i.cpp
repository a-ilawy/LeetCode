class Solution {
public:
    vector<int> initDiffArray(vector<int> &arr)
    {
        int n = arr.size();

        // Initialize difference array with an extra element
        vector<int> d(n + 1, 0);

        d[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            d[i] = arr[i] - arr[i - 1];
        }
        return d;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> d = initDiffArray(nums);

        // for (int i = 0; i < d.size(); i++)
        // {
        //    cout<<d[i]<<",";
        // }

        for(int i=0;i<queries.size();i++){

            int start = queries[i][0];
            int end = queries[i][1];
            d[start]--;
            d[end+1]++;
            
        }
        nums[0] = d[0];
        for(int i=1;i<nums.size();i++){

            nums[i] = d[i] + nums[i-1];
            
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){return false;}
        }
        return true;
    }
};