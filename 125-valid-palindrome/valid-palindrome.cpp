class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n<1) return true;

        int l=0;
        int r = n-1;
       while(l<r) {
            while ( l<n && !isalnum(static_cast<unsigned char>(s[l]))){
                l++;
            }
            if(l==n) return true;
            while (r > 0 && !isalnum(static_cast<unsigned char>(s[r]))) r--;
            cout<<tolower(s[l])<<" = "<<tolower(s[r])<<endl;
            if(tolower(s[l]) != tolower(s[r])) return false;
            else{
                l++;
                r--;
            }
           
        }
        return true;
    }
};