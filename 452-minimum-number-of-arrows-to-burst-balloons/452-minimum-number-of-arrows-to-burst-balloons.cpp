class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto &point: points){
            minEnd = min(minEnd,point[1]);
            if(point[0] > minEnd){
                count++;
                minEnd = point[1];
            }
        }
        return count;
    }
};