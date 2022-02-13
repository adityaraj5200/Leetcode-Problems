class Solution {
public:
    vector<vector<int>> result;
    
    void helper(vector<int> &nums,int i,int mask){ // mask tells which element to take or not
        if(i==nums.size()){
            vector<int> curr;
            for(int i=0;i<nums.size();i++)
                if(mask&(1<<i))
                    curr.push_back(nums[i]);
            result.push_back(curr);
            return;
        }
        
        mask |= 1<<i;
        helper(nums,i+1,mask);
        mask ^= 1<<i;
        helper(nums,i+1,mask);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0,0);
        return result;
    }
};