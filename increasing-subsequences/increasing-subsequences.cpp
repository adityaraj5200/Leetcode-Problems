class Solution{
public:
    void helper(vector<vector<int>>& result,vector<int>& curr,vector<int>& nums,int index){
        if(curr.size() >= 2) result.push_back(curr);
        if(index==nums.size()) return;
        unordered_set<int> hash;
        for(int i=index;i<nums.size();i++){
            if((curr.empty() || nums[i]>=curr.back()) && hash.find(nums[i])==hash.end()){
                curr.push_back(nums[i]);
                hash.insert(nums[i]);
                helper(result,curr,nums,i+1);
                curr.pop_back();
            }
            
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(result,curr,nums,0);
        return result;
    }
};