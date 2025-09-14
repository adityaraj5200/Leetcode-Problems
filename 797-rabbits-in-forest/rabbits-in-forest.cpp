class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,vector<int>> mp;
        for(int& f: answers){
            if(mp.find(f) == mp.end()){
                mp[f] = {0};
            }

            if(mp[f].back() == f+1){
                mp[f].push_back(0);
            }
            
            mp[f].back()++;
        }

        int ans = 0;
        for(auto p: mp){
            vector<int>& v = p.second;
            for(int f: v){
                ans += max(f,p.first+1);
            }
        }

        return ans;
    }
};