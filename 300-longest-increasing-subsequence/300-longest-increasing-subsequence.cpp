class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis = {nums[0]};
        for(int i=1;i<nums.size();i++){
            if(nums[i] > lis.back())
                lis.push_back(nums[i]);
            else
                *lower_bound(lis.begin(),lis.end(),nums[i]) = nums[i];
        }
        
        return lis.size();
    }
};