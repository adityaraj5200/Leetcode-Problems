class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end());
        int left = nums[0], right = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1) right = nums[i];
            
            else{
                if(left == right)
                    result.push_back(to_string(left));
                else
                    result.push_back(to_string(left)+"->"+to_string(right));
                right = left = nums[i];
            }
        }
        if(left == right) 
            result.push_back(to_string(left));
        else
            result.push_back(to_string(left)+"->"+to_string(right));
        
        return result;
    }
};

