class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int remainder = 0, n = nums.size();
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++){
            remainder = ((remainder*2) + nums[i])%5;
            ans[i] = remainder==0 ? true : false;
        }

        return ans;
    }
};