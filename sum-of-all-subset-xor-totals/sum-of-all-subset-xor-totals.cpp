class Solution {
public:
    int helper(vector<int>& nums,int i,int xorr){
        if(i==nums.size()) return xorr;
        return helper(nums,i+1,xorr) + helper(nums,i+1,xorr^nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};