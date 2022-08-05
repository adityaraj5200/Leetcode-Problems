class Solution {
public:
    void recurse(int idx,vector<int>& candidates,int target,vector<int>& curr,vector<vector<int>>& ans){
        if(target<0) return;
        
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        
        curr.push_back(candidates[idx]);
        recurse(idx,candidates,target-candidates[idx],curr,ans);
        curr.pop_back();
        recurse(idx+1,candidates,target,curr,ans);
        // recurse(idx+1,candidates,target,curr,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end(),greater<int>());
        vector<int> curr;
        vector<vector<int>> ans;
        recurse(0,candidates,target,curr,ans);
        return ans;
    }
};