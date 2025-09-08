class Solution {
public:

    bool has_zero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return true; // found zero
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int a = 1;
        int b = n-1;
        while(a<n){
            if(!has_zero(a) and !has_zero(b)) break;
            a++;
            b = n-a;
        }
        res.push_back(a);
        res.push_back(b);

        return res;
    }
};