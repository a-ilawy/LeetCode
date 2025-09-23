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
        uint8_t largeFreq =0;
        uint8_t cnt = largeFreq;

        for(int i=0; i< nums.size(); i++){
             freq[nums[i]]++;
             uint8_t f = freq[nums[i]];
             if(f > largeFreq){
                largeFreq = f;
                cnt = f;
             }else if (f == largeFreq){
                 cnt += f;
             }
           
        }
        
        return cnt;
    }
};