class Solution{
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> vec(n);
        for(int i=0,n=trust.size();i<n;i++){
            vec[trust[i][0]-1].first++;
            vec[trust[i][1]-1].second++;
        }
        
        for(int i=0,n=vec.size();i<n;i++)   
            if(vec[i].first==0 && vec[i].second==n-1)
                return i+1;
        
        return -1;
    }
};