class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        int sP = 0;
        int tP=0;
        while(sP < sLen && tP < tLen){
            if(s[sP] == t[tP]){
                sP++;
                tP++;
            }else{
                tP++;
            }
        }
        if(sP==sLen) return true;
        return false;
    }
};