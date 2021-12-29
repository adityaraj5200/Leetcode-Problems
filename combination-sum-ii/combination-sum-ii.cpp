class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;
    
    void helper(vector<int>& candidates,int st,int sum,int &target){
        if(sum >= target){
            if(sum==target)
                result.push_back(curr);
            return;
        }
        
        for(int i=st;i<candidates.size();i++){
            if(i!=st && candidates[i]==candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            helper(candidates,i+1,sum+candidates[i],target);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,0,target);
        return result;
    }
};