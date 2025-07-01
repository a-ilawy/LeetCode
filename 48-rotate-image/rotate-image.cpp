class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0,
            colEnd = matrix[0].size() - 1;
        vector<int> res;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {

            // go up
            for (int i = rowEnd; i >= rowBegin; i--) {
                res.push_back(matrix[i][colBegin]);
            }
            colBegin++;

            // go right
            for (int i = colBegin; i <= colEnd; i++) {
                res.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;

            // go down
            if (colBegin <= colEnd) {
                for (int i = rowBegin; i <= rowEnd; i++) {
                    res.push_back(matrix[i][colEnd]);
                }
                colEnd--;
            }

            // go left
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    res.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            
        }
       for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" , ";
       }
       int ct=0, n = res.size();
        rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0,
            colEnd = matrix[0].size() - 1;
      while (rowBegin <= rowEnd && colBegin <= colEnd && ct <n) {

            // go right
            for (int i = colBegin; i <= colEnd; i++) {
              matrix[rowBegin][i] = res[ct];
              ct++;
            }
            rowBegin++;

            // go down
            for (int i = rowBegin; i <= rowEnd; i++) {
                matrix[i][colEnd]= res[ct];
                ct++;
            }
            colEnd--;


            // go left
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                   matrix[rowEnd][i] = res[ct];
              ct++;
                }
                rowEnd--;
            }


            // go up
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                   matrix[i][colBegin]= res[ct];
              ct++;
                }
                colBegin++;
            }
        }
    }
};