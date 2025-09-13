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

        for(auto c : s){
            if (isVowel(c)){
                mp[c]++;
                maxVowelFreq = max(maxVowelFreq,mp[c]);
            }else{
                mp[c]++;
                maxConsonantFreq = max(maxConsonantFreq,mp[c]);
            }
        }

        return maxConsonantFreq + maxVowelFreq;
    }
};