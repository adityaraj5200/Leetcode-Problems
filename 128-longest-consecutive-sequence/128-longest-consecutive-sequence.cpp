class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int &val: nums){
            if(m[val]) continue;
            m[val] = m[val-m[val-1]] = m[val+m[val+1]] = 1+m[val+1]+m[val-1];
            ans = max(ans,m[val]);
        }
        return ans;
    }
};