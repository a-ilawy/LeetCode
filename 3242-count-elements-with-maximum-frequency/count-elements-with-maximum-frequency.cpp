class Solution {
public:
    // void printFreq(vector<int>& freq){
    //     cout<<endl;
    //     for(int i=0; i< freq.size(); i++){
    //         cout<<freq[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq (101, 0);
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
           
        }

        int largeFreq = freq[0];
        int indx = 0;
        for(int i=0; i< freq.size(); i++){
            if(freq[i] > largeFreq){
                largeFreq = freq[i];
                indx=i;
            }
        }
        
        int cnt = largeFreq;
        for(int i=0; i< freq.size(); i++){
            if( i != indx && freq[i] == largeFreq) {
                cnt +=freq[i];
            }
        }
        return cnt;
    }
};