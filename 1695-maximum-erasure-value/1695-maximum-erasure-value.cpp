class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, ans = 0;
        vector<bool> seen(1e5+1,false);
        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            if(!seen[nums[j]]){
                seen[nums[j]] = true;
                sum += nums[j++];
                ans = max(ans, sum);
            }
            else{
                seen[nums[i]] = false;
                sum -= nums[i++];
            }
        }
        
        return ans;
    }
};