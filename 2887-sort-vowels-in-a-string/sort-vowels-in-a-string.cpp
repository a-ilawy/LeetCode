class Solution {
public:

    bool isVowel(char c){
        c = tolower(c);
        if (c=='a' || c == 'e' || c == 'i' || c=='o' || c == 'u') return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowelArray;
        for(int i=0; i< s.size(); i++){
            if(isVowel(s[i])){
                vowelArray.push_back(s[i]);
            }
        }

        sort(vowelArray.begin(), vowelArray.end());
        
        int idx = 0;
        for(int i=0; i< s.size(); i++){
            if(isVowel(s[i])){
                s[i] = vowelArray[idx];
                idx++;
            }
        }
        return s;
    }
};