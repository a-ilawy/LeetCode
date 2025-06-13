class Solution {
public:
 
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, r = 0, maxLen = 0;
        
        while (r < s.size()) {
            if (window.find(s[r]) == window.end()) {
                window.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                window.erase(s[l]);
                l++;
            }
        }
        
        return maxLen;
    }
};
