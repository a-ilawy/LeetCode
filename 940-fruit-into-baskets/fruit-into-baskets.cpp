#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int start = 0, maxLen = 0;
        // unordered_map<int, int> basket;

        // for (int end = 0; end < fruits.size(); ++end) {
        //     basket[fruits[end]]++;

        //     while (basket.size() > 2) {
        //         basket[fruits[start]]--;
        //         if (basket[fruits[start]] == 0) {
        //             basket.erase(fruits[start]);
        //         }
        //         start++;
        //     }

        //     maxLen = max(maxLen, end - start + 1);
        // }

        // return maxLen;
        int last = -1, secondLast = -1;
        int lastCount = 0, curr = 0, maxFruits = 0;

        for (int fruit : fruits) {
            if (fruit == last || fruit == secondLast) {
                curr++;
            } else {
                curr = lastCount + 1;
            }

            if (fruit == last) {
                lastCount++;
            } else {
                lastCount = 1;
                secondLast = last;
                last = fruit;
            }

            maxFruits = max(maxFruits, curr);
        }

        return maxFruits;
    }
};