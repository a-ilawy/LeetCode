class Solution {
public:
    int strStr(string haystack, string needle) {
        int hP = 0;
        int lastIdx = needle.length();
        while(hP < haystack.length()){
             cout<<needle[0]<<" , "<<haystack[hP]<<endl;
            if(needle[0] != haystack[hP]){
                hP++;
            }else{
               // compare two string
               string newStr = haystack.substr(hP, lastIdx);
               cout<<newStr<<" , nP: "<<hP<<" , lastIdx: "<<lastIdx<<endl;
            //    while(newStr.length() > needle.length()){
            //     newStr = haystack.substr(hP, hP + lastIdx-1);
            //    }
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