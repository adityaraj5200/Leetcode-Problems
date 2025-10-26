class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> idx(3);
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            idx[s[i]-'a'].push_back(i);
        }
        
        for(int i=0;i<3;i++){
            idx[i].push_back(n);
        }

        int ptr[3]={0,0,0};
        while(max({idx[0][ptr[0]],idx[1][ptr[1]],idx[2][ptr[2]]})<n){
            int mn = min({idx[0][ptr[0]],idx[1][ptr[1]],idx[2][ptr[2]]});
            int mx = max({idx[0][ptr[0]],idx[1][ptr[1]],idx[2][ptr[2]]});
            ans += n-mx;
            for(int i=0;i<3;i++){
                if(idx[i][ptr[i]]==mn){
                    ptr[i]++;
                }
            }
        }
        return ans;
    }
};
