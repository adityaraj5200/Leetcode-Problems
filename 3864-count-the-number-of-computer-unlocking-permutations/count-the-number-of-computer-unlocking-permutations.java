class Solution {
    public int countPermutations(int[] complexity) {
        long ans = 1, factorial = complexity.length-1, MOD = (long)1e9+7L;
        for(int i=1;i<complexity.length;i++){
            ans = (ans*i)%MOD;
            
            if(complexity[i] <= complexity[0])
                return 0;
        }

        return (int)ans;
    }
}