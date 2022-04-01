class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result = {intervals[0]};
        for(vector<int>& vec: intervals){
            if(vec[0] > result.back()[1])
                result.push_back(vec);
            else
                result.back()[1] = max(result.back()[1],vec.back());
        }
        
        return result;
    }
};