class Solution {
public:

    bool isVowel(char c){
        if (c=='a' || c == 'e' || c == 'i' || c=='o' || c == 'u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        int maxVowelFreq=0;
        int maxConsonantFreq=0;
        unordered_map<char, int> mp;

        for(int i=0;i<s.size();i++){
            if (isVowel(s[i])){
                mp[s[i]]++;
                maxVowelFreq = max(maxVowelFreq,mp[s[i]]);
            }else{
                mp[s[i]]++;
                maxConsonantFreq = max(maxConsonantFreq,mp[s[i]]);
            }
        }

        return maxConsonantFreq + maxVowelFreq;
    }
};