class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i=0,n=nums.size();i<n;i++){
            int mx=-1e9,mn=1e9;
            for(int j=i;j<n;j++){
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                ans += 1LL*(mx-mn);
            }
        }

        return ans;
    }
};