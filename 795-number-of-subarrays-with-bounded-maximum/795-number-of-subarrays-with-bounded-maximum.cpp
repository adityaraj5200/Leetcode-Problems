class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), ans = 0, behind = -1, ahead = -1;
        for(int i=0;i<n;i++){
            if(nums[i] > right) behind = i;
            if(nums[i] >= left) ahead = i;
            ans += ahead-behind;
        }
        return ans;
    }
};