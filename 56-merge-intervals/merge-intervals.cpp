// Time Complexity: O(n log n), where n = number of intervals
// Space Complexity: O(n)

// Approach:
// 1. Sort all intervals by their start time to ensure chronological order.
// 2. Initialize `maxEndTime` to track the furthest end seen so far.
// 3. Traverse each interval:
//      - If the current interval starts after `maxEndTime`, it means no overlap → push it to the result.
//      - Otherwise, the current interval overlaps with the previous → merge them by updating the last interval’s end time.
// 4. Update `maxEndTime` after every interval to the maximum of current and previous end times.
// 5. Return the merged list of intervals.

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