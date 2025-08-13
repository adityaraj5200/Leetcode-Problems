class Solution {
    public boolean isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;

        int limit = Math.min(n,(Integer.MAX_VALUE/3)), val = 1;
        while(val<limit){
            val *= 3;
        }

        return val==n && val%3==0;
    }
}