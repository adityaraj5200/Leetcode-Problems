class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = *max_element(nums.begin(),nums.end()), maxLen=0, currLen=0;
        for(int &num: nums){
            currLen = num==maxAND ? currLen+1 : 0;
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};