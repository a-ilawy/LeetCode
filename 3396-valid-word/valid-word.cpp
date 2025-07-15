class Solution {
public:
    bool isValid(string word) {
      
        regex allowed("^[A-Za-z0-9]{3,}$");           
        regex hasVowel("[AEIOUaeiou]");                
        regex hasConsonant("[B-DF-HJ-NP-TV-Zb-df-hj-np-tv-z]"); 
         return regex_match(word, allowed) &&
                regex_search(word, hasVowel) &&
                regex_search(word, hasConsonant);
    }
};