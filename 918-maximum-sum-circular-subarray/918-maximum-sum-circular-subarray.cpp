class Solution{
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int maxSum = INT_MIN, minSum = INT_MAX, currMax = 0, currMin = 0, totalSum = 0;
        for(int &val: nums){
            currMax = max(currMax+val, val);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+val, val);
            minSum = min(minSum, currMin);
            totalSum += val;
        }
        
        return maxSum < 0 ? maxSum : max(maxSum, totalSum-minSum);
    }
};