class Solution {
public:

    bool isVowel(char c){
        if (c=='a' || c == 'e' || c == 'i' || c=='o' || c == 'u') return true;
        return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> vowelM;
        unordered_map<char, int> consonantM;

        for(auto c : s){
            if (isVowel(c)){
                vowelM[c]++;
            }else{
                consonantM[c]++;
            }
        }

        int maxVowelFreq=0;
        for(auto m : vowelM){
        maxVowelFreq = max(maxVowelFreq,m.second);
        }

        int maxConsonantFreq=0;
        for(auto m : consonantM){
        maxConsonantFreq = max(maxConsonantFreq,m.second);
        }

        return maxConsonantFreq + maxVowelFreq;
    }
};