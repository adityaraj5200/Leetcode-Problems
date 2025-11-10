class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        dp.assign(n, vector<int>(4001,-1));
        return helper(0,0,rewardValues);
    }
private:
    vector<vector<int>> dp;
    int helper(int idx, int currTotalReward, vector<int>& rewardValues){
        if(idx == rewardValues.size()){
            return currTotalReward;
        }

        if(dp[idx][currTotalReward] != -1){
            return dp[idx][currTotalReward];
        }

        int take = (currTotalReward<rewardValues[idx]) ? helper(idx+1, currTotalReward+rewardValues[idx], rewardValues) : 0;
        int skip = helper(idx+1, currTotalReward, rewardValues);

        return dp[idx][currTotalReward] = max(take,skip);
    }
};