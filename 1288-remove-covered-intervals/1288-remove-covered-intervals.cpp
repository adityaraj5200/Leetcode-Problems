class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        int left = -1, right = -1;
        for(vector<int> &interval: intervals){
            if(interval[0]!=left && interval[1]>right){
                left = interval[0];
                ans++;
            }
            
            right = max(right,interval[1]);
        }
        
        return ans;
    }
};