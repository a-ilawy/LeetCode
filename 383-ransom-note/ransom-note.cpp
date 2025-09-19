class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()) return false;
        unordered_map<char, int> mp;
        // for(int i=0;i<ransomNote.length();i++) mp[ransomNote[i]]+=1;
        // for(int i=0;i<magazine.length();i++) if(mp[magazine[i]]>0)mp[magazine[i]]--;
        // for(int i=0;i<ransomNote.length();i++) if (mp[ransomNote[i]]!=0) return false;
        // return true;

        for(int i=0;i<magazine.length();i++) mp[magazine[i]]++;
        for(int i=0;i<ransomNote.length();i++){
             if(mp[ransomNote[i]]==0)return false; 
             mp[ransomNote[i]]--;
        }
        return true;

    }
};