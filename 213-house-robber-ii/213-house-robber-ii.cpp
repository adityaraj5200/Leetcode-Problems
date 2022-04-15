class Solution {
public:
    int helper(vector<int>& nums,int st,int end){
        int include = nums[st], exclude = 0;
        for(int i=st+1;i<=end;i++){
            int tempinc = include, tempexc = exclude;
            include = exclude + nums[i];
            exclude = max(tempinc, tempexc);
        }
        return max(include,exclude);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helper(nums,0,nums.size()-2), helper(nums,1,nums.size()-1));
    }
};