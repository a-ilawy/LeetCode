class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int X1 = points[i][0];
                    int X2 = points[j][0];
                    int X3 = points[k][0];

                    int Y1 = points[i][1];
                    int Y2 = points[j][1];
                    int Y3 = points[k][1];

                    double area = 0.5 * abs(X1*(Y2-Y3) + X2*(Y3-Y1) + X3*(Y1-Y2));
                    maxArea = max(maxArea, area);

                }
            }
        }
        return maxArea;
    }
};