class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;
    void helper(vector<int>& candidates,int i,int sum,int target){
        if(sum>target)
            return;
        
        if(i==candidates.size()){
            if(sum==target) result.push_back(curr);
            return;
        }
        
        curr.push_back(candidates[i]);
        helper(candidates,i,sum+candidates[i],target);
        curr.pop_back();
        helper(candidates,i+1,sum,target);
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        helper(candidates,0,0,target);
        return result;
    }
};