class Solution{
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        sort(trust.begin(),trust.end());
        unordered_map<int,vector<int>> hashmap;
        unordered_set<int> potential_ans;
        for(int i=1;i<=n;i++)
            potential_ans.insert(i);
        for(int i=0;i<trust.size();i++){
            hashmap[trust[i][1]].push_back(trust[i][0]);
            if(potential_ans.find(trust[i][0]) != potential_ans.end())
                potential_ans.erase(trust[i][0]);
        }
        int ans = -1;
        for(const int &val: potential_ans)
            if(hashmap[val].size() == n-1){
                if(ans == -1)
                    ans = val;
                else return -1;
            }
            
        return ans;
    }
};