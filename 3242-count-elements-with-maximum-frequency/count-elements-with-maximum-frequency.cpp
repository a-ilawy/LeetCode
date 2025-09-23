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
        uint8_t freq[101] = {0};
        for(int i=0; i< nums.size(); i++){
            freq[nums[i]]++;
           
        }

        uint8_t largeFreq = freq[0];
        uint8_t indx = 0;
        for(int i=0; i< 101; i++){
            if(freq[i] > largeFreq){
                largeFreq = freq[i];
                indx=i;
            }
        }
        
        uint8_t cnt = largeFreq;
        for(int i=0; i< 101; i++){
            if( i != indx && freq[i] == largeFreq) {
                cnt +=freq[i];
            }
        }
        return cnt;
    }
};