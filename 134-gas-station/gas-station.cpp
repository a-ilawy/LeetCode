class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGase = 0;
        int totalCost = 0;
        for(int i=0; i<gas.size();i++){
            totalGase+=gas[i];
            totalCost+=cost[i];
        }
        if(totalGase < totalCost)return -1;
        int start=0;
        int currgas=0;
        for(int i=0; i<gas.size();i++){
            currgas += gas[i] - cost[i];
            if(currgas<0){
                start=i+1;
                currgas=0;
            }
        }
        return start;
    }
};