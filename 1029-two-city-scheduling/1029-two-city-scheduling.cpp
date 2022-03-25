class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int> a,vector<int> b){
            return a[1]-a[0] < b[1]-b[0];
        });
        int ans = 0, i=0, n = costs.size();
        while(i<n/2){
            ans += costs[i++][1];
        }
        while(i<n){
            ans += costs[i++][0];
        }
        return ans;
    }
};