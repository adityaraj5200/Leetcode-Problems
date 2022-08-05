class Solution {
public:
    void recurse(int idx,vector<int>& candidates,int target,vector<int>& curr,vector<vector<int>>& ans,int k){
        
        if(target<0 || k<0) return;
        
        if(idx==candidates.size()){
            if(target==0 && k==0){
                ans.push_back(curr);
            }
            return;
        }
        
        curr.push_back(candidates[idx]);
        recurse(idx+1,candidates,target-candidates[idx],curr,ans,k-1);
        curr.pop_back();
        recurse(idx+1,candidates,target,curr,ans,k);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        // sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        recurse(0,candidates,n,curr,ans,k);
        return ans;        
    }
};