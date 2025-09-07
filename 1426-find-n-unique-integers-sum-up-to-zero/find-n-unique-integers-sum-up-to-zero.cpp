class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n%2==0){
            while(n>1){
                res.push_back(n);
                res.push_back(-n);
                n-=2;
            }
        }else{
            while(n>1){
                res.push_back(n);
                res.push_back(-n);
                n-=2;
            }
             res.push_back(0);
        }
        return res;
    }
};