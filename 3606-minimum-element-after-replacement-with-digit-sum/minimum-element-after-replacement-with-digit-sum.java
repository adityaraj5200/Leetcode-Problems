class Solution {
    public int minElement(int[] nums) {
        int ans = 1000000;
        for(int i=0;i<nums.length;i++){
            int num = nums[i];
            int sumOfDigits=0;
            while(num > 0){
                sumOfDigits += num%10;
                num /= 10;
            }
            ans = Math.min(ans,sumOfDigits);
        }

        return ans;
    }
}