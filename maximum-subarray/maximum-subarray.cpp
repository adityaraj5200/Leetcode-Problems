class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0,bestSum=INT_MIN;
        for(int& val: nums){
            currSum += val;
            if(currSum > bestSum) bestSum = currSum;
            if(currSum < 0) currSum=0;
        }
        return bestSum;
    }
};