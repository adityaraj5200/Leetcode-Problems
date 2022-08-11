class Solution {
public:    
    int numTrees(int n) {
        vector<int> dp(n+1,0); // dp[i] will tell me in how many ways I can make unique BST's when I am given 'i' nodes.
        dp[0] = dp[1] = 1;
        
        for(int curr_n=2;curr_n <= n;curr_n++){
            int leftNodes = 0, rightNodes = curr_n-1;
            while(leftNodes < curr_n){
                dp[curr_n] += dp[leftNodes] * dp[rightNodes];
                leftNodes++;
                rightNodes--;
                // cout<<"dp[curr_n] = "<<dp[curr_n]<<endl;
            }
            // cout<<endl;
        }
        
        return dp[n];
    }
};