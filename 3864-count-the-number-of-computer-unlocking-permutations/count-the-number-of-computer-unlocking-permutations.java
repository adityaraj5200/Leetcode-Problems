class Solution {
    public int countPermutations(int[] complexity) {
        for(int i=1;i<complexity.length;i++){
            if(complexity[i] <= complexity[0])
                return 0;
        }

        long ans = 1, factorial = complexity.length-1, MOD = (long)1e9+7L;
        for(long f=factorial;f>0;f--){
            ans = (ans*f)%MOD;
        }

        return (int)ans;
    }
}