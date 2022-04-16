class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachidx = 0, n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(i > reachidx)
                return false;
            
            reachidx = max(reachidx, i+nums[i]);
            if(reachidx >= n-1) return true;
        }
        
        return false;
    }
};