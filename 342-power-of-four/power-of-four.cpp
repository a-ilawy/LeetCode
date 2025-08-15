class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n==0) return false;
        double x = log(n)/log(4);
        // cout<<x<<" , "<<ceil(x);
        return ceil(x) == x? true : false ;
    }
};