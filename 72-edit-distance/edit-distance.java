class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int[][] dp = new int[n][m];
        for(int i=0;i<dp.length;i++){
            Arrays.fill(dp[i],-1);
        }
        return helper(word1, word2, 0, 0, dp);
    }

    private int helper(String word1, String word2, int i, int j, int[][] dp){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1.charAt(i) == word2.charAt(j)){
            dp[i][j] = helper(word1, word2, i+1, j+1, dp);
        }
        else{
            int insert = helper(word1, word2, i, j+1, dp);
            int delete = helper(word1, word2, i+1, j, dp);
            int replace = helper(word1, word2, i+1, j+1, dp);
            dp[i][j] = 1 + Math.min(insert, Math.min(delete, replace));
        }

        return dp[i][j];
    }
}

/*
insert - i,j+1
delete - i+1,j
replace - i+1, j+1

 */