class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0,
            colEnd = matrix[0].size() - 1;
        vector<int> res;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {

            // go right
            for (int i = colBegin; i <= colEnd; i++) {
                res.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;

            // go down
            for (int i = rowBegin; i <= rowEnd; i++) {
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;


            // go left
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    res.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }


            // go up
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    res.push_back(matrix[i][colBegin]);
                }
                colBegin++;
            }
        }
        return res;
    }
};