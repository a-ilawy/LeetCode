class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq (101, 0);
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
           
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
       
        int cnt = freq[0];
        int largeFreq = freq[0];
        for(int i=1; i< freq.size(); i++){
            if(freq[i] == largeFreq) {cnt +=freq[1];}
            else{
                break;
            }
        }
        return cnt;

    }
};