class Solution {
public:
    char kthCharacter(int k) {
        int size = 0;
        string s="a";
        while(size < k){
            string newPart = "";
            for(auto c:s){
                if (c=='z') newPart+='a';
                else{
                    newPart+= char(int(c)+1);
                }
            }
          
            s+=newPart;
          
            size = s.length();
        }
        return s[k-1];
    }
};
// bccd -> abbcbccd
//bccdcdde -> abbcbccdbccdcdde