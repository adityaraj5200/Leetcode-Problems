class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, curr_sum = 0;
        for(int &val: nums){
            curr_sum += val;
            ans = max(ans, curr_sum);
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return ans;
    }
};