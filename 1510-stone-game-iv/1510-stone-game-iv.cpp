class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,false);
        //0 1 2 3 4 5 6 7 8 9
        //F T F T T F T F T T
        for(int curr = 1; curr<=n ; curr++){
            for(int sq=1;curr >= sq*sq; sq++){
                if(dp[curr-(sq*sq)] == false){
                    dp[curr] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};