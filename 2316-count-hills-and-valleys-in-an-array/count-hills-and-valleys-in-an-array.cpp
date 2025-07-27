class Solution {
public:
    int hillsAndVallyes(vector<int> n, int i, int dir, int curr){
        if( i == n.size() || i<0) return -1;

        
        if(curr!=n[i]) return i;

        return hillsAndVallyes(n,i+dir,dir,curr);

    }
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int l=0;
        int r=0;
        for(int i=1;i<n;i++){

            int currValue = nums[i];

            l = hillsAndVallyes(nums,i,-1, currValue);
            r = hillsAndVallyes(nums,i,1, currValue);
            
            if (l < 0 || r <0) continue;
            if (nums[i] == nums[i-1]) continue;
            if((currValue > nums[l] && currValue > nums[r] ) || (currValue < nums[l] && currValue < nums[r] )){
                cnt++;
            }
       

        }
        return cnt;
    }
};