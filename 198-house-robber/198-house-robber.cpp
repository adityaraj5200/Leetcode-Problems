class Solution {
public:
    int rob(vector<int>& nums) {
        int include = 0, exclude = 0;
        for(int &val: nums){
            int prev_inc = include, prev_exc = exclude;
            include = prev_exc + val;
            exclude = max(prev_inc, prev_exc);
        }
        
        return max(include, exclude);
    }
};