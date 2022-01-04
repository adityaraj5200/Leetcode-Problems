class Solution {
public:
    vector<vector<int>> result;
    vector<int> curr;
    int n;
    
    void helper(vector<int>& nums) {
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(nums[i] != INT_MIN){
                int val = nums[i];
                curr.push_back(nums[i]);
                nums[i] = INT_MIN;
                helper(nums);
                nums[i] = val;
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        helper(nums);
        return result;
    }
};