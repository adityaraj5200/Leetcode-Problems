class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,false);
        //0 1 2 3 4 5 6 7 8 9
        //F T F T T F T F T T
        dp[1] = true;
        for(int curr = 2; curr<=n ; curr++){
            int sq=1;
            
            while(curr - (sq*sq) >= 0){
                if(dp[curr-(sq*sq)] == false){
                    dp[curr] = true;
                    break;
                }
                sq++;
            }
        }
        
        return dp[n];
    }
};