class Solution {
public:
    int romanSymbolToValue(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        default:
            return 1000;
        }
    }

    int romanToInt(string s) {
        int res = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = romanSymbolToValue(s[i]);
            if (i > 0) {
                int nextValue = romanSymbolToValue(s[i - 1]);
                if (currValue > nextValue) {
                    res += currValue - nextValue;
                    i--;
                } else {
                    res += currValue;
                }
            }

            else {
                res += currValue;
            }
        }

        return res;
    }
};