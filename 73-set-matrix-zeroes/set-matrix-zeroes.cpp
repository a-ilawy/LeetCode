class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> arrZeros;
       
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(matrix[i][j]==0){
                    arrZeros.push_back({i, j});
                   
                }
            }
        }

        for(int k=0; k<arrZeros.size();k++){
            // cout<<arrZeros[k][0]<<","<<arrZeros[k][1];
            int i=arrZeros[k][0];
            int j=arrZeros[k][1];
            for(int idx=0; idx<n;idx++){
                matrix[i][idx]=0;
            }
            for(int idx=0; idx<m;idx++){
                matrix[idx][j]=0;
            }

        }
    }
};