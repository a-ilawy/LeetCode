class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced =0;
        for(int i=0;i<fruits.size();i++){
            bool placed = false;
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j] && baskets[j]!=0){
                    baskets[j]=0;
                    placed = true;
                    break;
                }
            }
             if(!placed) unplaced++;
        }
        return unplaced;
    }
};

