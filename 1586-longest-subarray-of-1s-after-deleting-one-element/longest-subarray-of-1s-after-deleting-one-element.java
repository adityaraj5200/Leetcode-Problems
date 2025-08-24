class Solution {
    public int longestSubarray(int[] nums) {
        int i=0,j=0,n=nums.length,ans=0,cntOne=0,cntZero=0;
        while(i<n && j<n){

            while(cntZero==2){
                if(nums[i]==1){
                    cntOne--;
                }
                else{
                    cntZero--;
                }
                i++;
            }

            if(nums[j]==1){
                cntOne++;
            }
            else{
                cntZero++;
            }
            j++;

            ans = Math.max(ans, cntZero>0 ? cntOne : cntOne-1);

        }

        return ans;
    }
}