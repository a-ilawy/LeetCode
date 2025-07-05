class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            auto it = freq.find(arr[i]);
            if (it != freq.end()) {
                freq[arr[i]]++;
            } else {
                freq[arr[i]] = 1;
            }
        }
        int maxFreq = -1;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            // cout << it->first << ": " << it->second << endl;
            if (it->first == it->second)
                maxFreq = max(it->first, maxFreq);
        }

        return maxFreq;
    }
};