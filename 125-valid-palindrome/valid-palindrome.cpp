class Solution {
public:
    bool isPalindrome(string s) {
    //     int n = s.length();
    //     if(n<1) return true;

    //     int l=0;
    //     int r = n-1;
    //    while(l<r) {
    //         while ( l<n && !isalnum(static_cast<unsigned char>(s[l]))){
    //             l++;
    //         }
    //         if(l==n) return true;
    //         while (r > 0 && !isalnum(static_cast<unsigned char>(s[r]))) r--;
          
    //         if(tolower(s[l]) != tolower(s[r])) return false;
    //         else{
    //             l++;
    //             r--;
    //         }
           
    //     }
    //     return true;
        int left = 0, right = s.length() - 1;

            while (left < right) {
                // Skip non-alphanumeric characters from the left
                while (left < right && !std::isalnum(s[left])) left++;

                // Skip non-alphanumeric characters from the right
                while (left < right && !std::isalnum(s[right])) right--;

                // Compare characters case-insensitively
                if (std::tolower(s[left]) != std::tolower(s[right])) {
                    return false;
                }

                left++;
                right--;
            }

            return true;
    }
};