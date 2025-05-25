class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       map<string, int> m;
       int res=0;
       for(int i=0;i<words.size();i++){
        if(!m[words[i]]){
             reverse(words[i].begin(), words[i].end());
             m[words[i]] +=1;
        }
        else{
            res+=4;
            m[words[i]]--;
        }
       }
       for(auto v : m){
        cout<<v.first<<",";
        cout<<v.second<<",";
        if(v.second==1 && v.first[0]==v.first[1]){
            res+=2;
            break;
        }
       }
       return res;
    }
};