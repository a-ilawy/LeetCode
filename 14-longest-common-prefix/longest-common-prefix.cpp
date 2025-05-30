class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].length();
        int idx = 0;
        for(int i=0;i<strs.size();i++){
            if(strs[i].length() <= minLen){
                minLen = strs[i].length();
                idx = i;
            }
        }
        string prefix = strs[idx];
        for(auto currStr : strs){
           
           if(currStr!=prefix){
            int pIdx = 0;
            for(int j=0; j<prefix.length(); j++){
                // cout<<currStr<<" , "<<prefix<<endl;
                if(prefix[j]==currStr[j]){
                   pIdx++;
                }else{
                    break;
                }
            }
            prefix = prefix.substr(0, pIdx);
           }
            
        }
        return prefix;
    }
};