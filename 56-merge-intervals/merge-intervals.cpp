class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxEndTime = INT_MIN;
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });

        vector<vector<int>> ans;
        for(vector<int>& interval: intervals){
            int st = interval[0];
            int end = interval[1];

            if(st > maxEndTime){
                ans.push_back({st,end});
            }
            else{
                if(end > ans.back()[1]){
                    ans.back()[1] = end;
                }
            }
            maxEndTime = max(maxEndTime, end);
        }

        return ans;
    }
};