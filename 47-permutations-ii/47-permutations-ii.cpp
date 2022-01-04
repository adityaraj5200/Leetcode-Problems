class Solution {
private:
    vector<vector<int>> result;
    
    void permute(vector<int>& nums, int start){
        if (start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
            
        unordered_set<int> seen;  
        for (int i = start; i < nums.size(); ++i){
            if (seen.find(nums[i]) == seen.end()){
                swap(nums[start], nums[i]);
                permute(nums, start+1);
                swap(nums[start], nums[i]);  // backtrack
                seen.insert(nums[i]);
            }
        }     
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        permute(nums, 0);
        return result;
    }
};