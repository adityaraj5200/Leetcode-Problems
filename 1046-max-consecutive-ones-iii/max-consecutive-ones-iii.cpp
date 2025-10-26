class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int st=0,end=0,ans=0,n=nums.size(),zeroCount=0;
        while(end<n){
            if(nums[end++]==0){
                zeroCount++;
            }

            // Shrink window if more than k zeros
            while(zeroCount>k){
                if(nums[st]==0){
                    zeroCount--;
                }
                st++;
            }

            ans=max(ans,end-st);
        }
        return ans;
    }
};
