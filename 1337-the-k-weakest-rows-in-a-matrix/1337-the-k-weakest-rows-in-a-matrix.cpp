class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec;
        const int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j]) cnt++;
                else break;
            }
            vec.push_back({cnt,i});
        }
        
        sort(vec.begin(),vec.end());
        
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i] = vec[i].second;
        }
        
        return ans;
    }
};