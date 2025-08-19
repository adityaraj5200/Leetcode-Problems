class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans=0, consecutiveZeroesCount=0;
        for(int num: nums){
            consecutiveZeroesCount = (num==0) ? consecutiveZeroesCount+1 : 0;
            ans += consecutiveZeroesCount;
        }
        return ans;
    }
}