class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0, n=nums.size();
        int ans = INT_MAX, currsum = 0;
        while(l<n && r<n){
            currsum += nums[r++];
            while(currsum >= target){
                ans = min(ans,r-l);
                currsum -= nums[l++];
            }
        }
        
        if(ans == INT_MAX)
            ans = 0;
        
        return ans;
    }
};