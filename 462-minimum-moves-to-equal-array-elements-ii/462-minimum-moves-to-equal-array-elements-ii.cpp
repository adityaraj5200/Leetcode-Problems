class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int median = nums[n/2];
        int ans = 0;
        
        for(int val: nums){
            ans += abs(val-median);
        }
        
        return ans;
    }
};