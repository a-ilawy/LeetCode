class Solution {
public:
    int strStr(string haystack, string needle) {
        int hP = 0;
        int lastIdx = needle.length();
        while(hP < haystack.length()){
            if(needle[0] != haystack[hP]){
                hP++;
            }else{
               // compare two string
               string newStr = haystack.substr(hP, lastIdx);
               if(needle == newStr){
                return hP;
               }else{
                hP++;
               }
            }
        }
        return -1;
    }
};