class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].length();
        int idx = 0;
        for(int i=0;i<strs.size();i++){
            int currLen = strs[i].length();
            // cout<<currLen<<" , "<<minLen<<endl;
            if(currLen <= minLen){
                minLen = currLen;
                idx = i;
            }
        }
        string prefix = strs[idx];
        for(int i=0;i<strs.size();i++){
           
           if(i!=idx){
            string currStr = strs[i];
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