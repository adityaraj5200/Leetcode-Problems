class Solution{
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), dp[n];
        deque<int> dq;
        // front par maximum hoga and back par hoga minimum
        for(int i=n-1;i>=0;i--){
            dp[i] = nums[i] + (dq.empty() ? 0 : dp[dq.front()]);
            
            while(!dq.empty() && dp[i]>dp[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(dq.front()-dq.back() >= k)
                dq.pop_front();
        }
        
        return dp[0];
    }
};