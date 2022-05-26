class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans = {{intervals[0]}};
        
        for(int i=1;i<intervals.size();i++){
            int st = intervals[i][0], end = intervals[i][1];
            if(st <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], end);
            else ans.push_back({st,end});
        }
        
        return ans;
    }
};