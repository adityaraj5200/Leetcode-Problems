class Solution {
    public boolean isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int limit = Math.min(n,Integer.MAX_VALUE/4+1);
        int val = 1;
        while(val<limit){
            val *= 4;
        }

        return val==n;
    }
}