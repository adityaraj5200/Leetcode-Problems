class Solution {
public:
    int each_side_len;
    
    bool recurse(vector<int>& nums,int idx,int curr_side_len,int sides_found){
        if(sides_found == 4) // we can also make it 3
            return true;
        
        if(curr_side_len >= each_side_len)
            return curr_side_len==each_side_len && recurse(nums,0,0,sides_found+1);
        
        if(idx==nums.size())
            return false;
        
        if(nums[idx] == 0)
            return recurse(nums,idx+1,curr_side_len,sides_found);
        
        if(nums[idx] != 0){
            int val = nums[idx];
            nums[idx] = 0;
            bool pick = recurse(nums,idx+1,curr_side_len+val,sides_found);
            if(pick) return true;
            nums[idx] = val;
        }
        
        bool not_pick = recurse(nums,idx+1,curr_side_len,sides_found);
        return not_pick;
    }
    
    bool makesquare(vector<int>& matchsticks){
        int total_sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total_sum % 4 != 0)
            return false;
        
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        each_side_len = total_sum/4;
        
        return recurse(matchsticks,0,0,0);
    }
};