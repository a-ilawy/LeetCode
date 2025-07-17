class Solution {
public:
        // Here are 4 possibilities that apply this equation:
        // 1- all numbers even
        // 2- all numbers odd
        // 3- even followed by odd
        // 3- odd followed by even

    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0, countEvenOdd=0, countOddEven=0;

        for(auto num : nums){
            if(num % 2 ==0){
                countEven++;
                countEvenOdd = countOddEven+1;
            }else{
                countOdd++;
                countOddEven = countEvenOdd+1;
            }
        }
        return max({countEven,countOdd, countEvenOdd, countOddEven});
    }
};