class Solution {
public:
    void reverse(string &s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    string reverseWords(string s) {
        int len = s.length();
        int i = 0, j = 0;

        // Remove leading, trailing, and extra spaces
        while (j < len) {
            // Skip spaces
            while (j < len && s[j] == ' ') j++;
            // Copy word
            while (j < len && s[j] != ' ') s[i++] = s[j++];
            // Skip spaces
            while (j < len && s[j] == ' ') j++;
            // Add one space if more words exist
            if (j < len) s[i++] = ' ';
        }

        // Resize string to cleaned version
        s.resize(i);
        len = s.length();

        // Reverse entire string
        reverse(s, 0, len - 1);

        // Reverse each word
        int start = 0;
        for (int i = 0; i <= len; ++i) {
            if (i == len || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};