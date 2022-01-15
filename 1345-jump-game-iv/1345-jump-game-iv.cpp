class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]].push_back(i);
        
        vector<bool> vis(n,false);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        
        int jumps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();
                
                if(idx == n-1)
                    return jumps;

                for(int &next_idx: mp[arr[idx]]){
                    if(!vis[next_idx]){
                        vis[next_idx] = true;
                        q.push(next_idx);
                    }
                }
                mp.erase(arr[idx]);

                auto safelyPush = [&](int idx){
                    if(idx>=0 && idx<n && !vis[idx]){
                        vis[idx] = true;
                        q.push(idx);
                    }
                };
                
                safelyPush(idx+1);
                safelyPush(idx-1);
            }
            
            jumps++;
        }
        return jumps;
    }
};