class Solution {
public:
    int helper(vector<int> &nums,int target,vector<unsigned int> &dp){
        if(dp[target] != -1) return dp[target]; // Already calculated
        if(target==0) return 1; // found a way 
        
        unsigned int ans = 0;
        for(int &val: nums)
            if(target-val >= 0)
                ans += helper(nums,target-val,dp);
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,-1);
        dp[0] = 1;
        
        int ans = helper(nums,target,dp);
        return ans;
    }
};