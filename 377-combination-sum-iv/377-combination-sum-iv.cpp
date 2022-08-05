class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        
        for(int curr_target=1;curr_target<=target;curr_target++){
            for(int &val: nums){
                if(curr_target-val >= 0)
                    dp[curr_target] += dp[curr_target-val];
            }
        }
        
        return dp.back();
    }
};