class Solution {
    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for(int num: nums){
            ans += getSumOfDivisors(num);
        }

        return ans;
    }

    private int getSumOfDivisors(int x){
        int numOfDivisors = 0;
        int sum = 0;
        /**
            20:
            1 20
            2 10
            4 5
         */

        for(int i=1;i*i<=x && numOfDivisors<=4;i++){
            int d1 = i;
            if(x%d1 == 0){
                numOfDivisors++;
                sum += d1;
                int d2 = x/i;
                if(d2 != d1){
                    numOfDivisors++;
                    sum += d2;
                }
            }
        }

        return numOfDivisors==4 ? sum : 0;
    }
}