class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        double res=0;
        
        for(int i=0;i<n;i++){
            double diff = (double)(classes[i][0]+1)/(double)(classes[i][1]+1) -
                          (double)(classes[i][0])/(double)(classes[i][1]);
            pq.push({diff, i});
        }

        while(extraStudents--){
            pair<double, int> bestClass = pq.top();
            pq.pop();

            int indx = bestClass.second;
            classes[indx][0]++;
            classes[indx][1]++;

            double diff = (double)(classes[indx][0]+1)/(double)(classes[indx][1]+1) -
                        (double)(classes[indx][0])/(double)(classes[indx][1]);
            pq.push({diff, indx});
        }
       
        while(!pq.empty()){
            int indx = pq.top().second;
            res+=(double)(classes[indx][0])/(double)(classes[indx][1]);
            pq.pop();
        }
        return (res/n);
    }
};