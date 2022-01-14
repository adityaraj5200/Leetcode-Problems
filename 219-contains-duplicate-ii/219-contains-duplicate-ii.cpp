class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastOcc;
        for(int i=0;i<nums.size();i++){ 
            if(lastOcc.find(nums[i])!=lastOcc.end() && i-lastOcc[nums[i]] <= k)
                return true;
            
            lastOcc[nums[i]] = i;
        }
        
        return false;
    }
};