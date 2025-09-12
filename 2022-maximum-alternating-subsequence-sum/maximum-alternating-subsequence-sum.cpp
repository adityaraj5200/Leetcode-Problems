class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dpPos(n), dpNeg(n);
        dpPos.back() = nums.back();
        dpNeg.back() = 0;
        for(int i=n-2;i>=0;i--){
            dpPos[i] = max(1LL*(nums[i])+dpNeg[i+1],dpPos[i+1]);
            dpNeg[i] = max(1LL*(-nums[i])+dpPos[i+1],dpNeg[i+1]);
        }

        return dpPos[0];
    }
};