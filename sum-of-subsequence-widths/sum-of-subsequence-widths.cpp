class Solution{
public:
    int sumSubseqWidths(vector<int>& nums){
        sort(nums.begin(), nums.end());
        long long int times = 1, res = 0, n = nums.size(), mod = 1e9+7;
        for(int i=0;i<n;i++,times=(times*2)%mod)
            res = (res + nums[i]*times - nums[n-1-i]*times)%mod;
        return res;
    }
};