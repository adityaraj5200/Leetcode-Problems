class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(), ans = INT_MIN;
        
        sort(events.begin(), events.end());
        map<int,int> mp; //start_time->value
        for(int i=n-1;i>=0;i--)
            mp[events[i][0]] = ans = max(ans, events[i][2]);
        
        for(int i=0;i<n;i++){
            auto it = mp.upper_bound(events[i][1]);
            ans = max(ans,it != mp.end() ? events[i][2] + it->second : 0);
        }
        
        return ans;
    }
};