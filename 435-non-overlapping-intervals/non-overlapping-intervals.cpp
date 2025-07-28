class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;

        sort(intervals.begin(),intervals.end());
        int remove=0;
        vector<int> last = {INT_MIN,INT_MIN};
        for(int i=0;i<n;i++){
            if(intervals[i][0] >= last[1]){
                last = intervals[i];
            }
            else{
                // overlap
                remove++;
                if(intervals[i][1] < last[1]){
                    last = intervals[i];
                }
            }
        }

        return remove;
    }
};