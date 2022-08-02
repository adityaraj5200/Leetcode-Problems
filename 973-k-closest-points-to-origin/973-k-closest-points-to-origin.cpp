class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxheap; // {distance,i}
        for(int i=0;i<points.size();i++){
            int &x = points[i][0], &y = points[i][1];
            int dist = x*x + y*y;
            maxheap.push({dist,i});
            if(maxheap.size() > k)
                maxheap.pop();
        }
        
        vector<vector<int>> ans(k);
        for(int i=0;i<k;i++){
            int idx = maxheap.top().second;
            maxheap.pop();
            ans[i] = points[idx];
        }
        
        return ans;
    }
};