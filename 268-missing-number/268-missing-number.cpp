class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size(), reqsum = (n*(n+1))/2;
        return reqsum - accumulate(nums.begin(),nums.end(),0);
    }
};