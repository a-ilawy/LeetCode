class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int count = 1; 
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                res += s[i - 1];
            }
        }

        res += s.back();
        return res;
    }
};
