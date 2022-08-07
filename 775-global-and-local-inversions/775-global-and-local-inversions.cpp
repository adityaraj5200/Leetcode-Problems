class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxSoFar = nums[0];
        for(int i=2;i<nums.size();i++){
            maxSoFar = max(maxSoFar, nums[i-2]);
            
            if(nums[i] < maxSoFar)
                return false;
            
        }
        
        return true;
    }
};