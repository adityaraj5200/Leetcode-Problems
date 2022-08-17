class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int n = arr.size();
        
        if(n==1)
            return 0;
        
        map<int,vector<int>> indices;
        for(int i=0;i<n;i++){
            indices[arr[i]].push_back(i);
        }
        
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        
        queue<int> q;
        q.push(0);
        
        int jumps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            jumps++;
            
            while(sz--){
                int curr_idx = q.front();
                q.pop();
                
                int front = curr_idx+1;
                int back = curr_idx-1;
                if(front<n && dp[front]>jumps){
                    dp[front] = jumps;
                    q.push(front);
                }
                if(back>=0 && dp[back]>jumps){
                    dp[back] = jumps;
                    q.push(back);
                }
                
                for(int other_idx: indices[arr[curr_idx]]){
                    if(dp[other_idx]>jumps){
                        dp[other_idx] = jumps;
                        q.push(other_idx);
                    }
                }
                indices.erase(arr[curr_idx]);
            }
        }
        
        return dp[n-1];
    }
};