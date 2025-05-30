class Solution {
public:
    int lengthOfLastWord(string s) {
        int ct = 0;
        int wordP = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                while(i>=0 && s[i]!=' '){
                    ct++;
                    i--;
                }
                break;
            }
        }
        return ct;
        
    }
};