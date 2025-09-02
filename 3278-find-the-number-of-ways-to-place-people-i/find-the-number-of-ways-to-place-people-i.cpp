class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points){
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });

        int ans = 0;
        for(int i=0;i<points.size();i++){
            stack<int> yAxis;
            int& endingPointY = points[i][1];
            for(int j=0;j<i;j++){
                int& currPointY = points[j][1];
                if(currPointY < endingPointY) continue;

                while(!yAxis.empty() && yAxis.top()>=currPointY){
                    yAxis.pop();
                }

                yAxis.push(currPointY);
            }
            ans += yAxis.size();
        }
        return ans;
    }
};