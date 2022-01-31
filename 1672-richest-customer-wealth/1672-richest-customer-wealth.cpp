class Solution{
public:
    int maximumWealth(vector<vector<int>>& accounts){
        int ans = INT_MIN;
        for(vector<int> &vec: accounts)
            ans = max(ans,accumulate(vec.begin(),vec.end(),0));
        return ans;
    }
};