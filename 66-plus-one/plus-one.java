class Solution {
    public int[] plusOne(int[] digits) {
        // 1,9,0,9,0,9,0
        // 1,9,0,9,0,9,1

        int n = digits.length;
        for(int i=n-1;i>=0;i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        int[] ans  = new int[n+1];
        ans[0] = 1;
        for(int i=1;i<=n;i++){
            ans[i] = 0;
        }

        return ans;
    }
}