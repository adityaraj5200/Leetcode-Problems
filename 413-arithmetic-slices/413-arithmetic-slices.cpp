class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int ans = 0, len = 2;
        int diff = nums[1]-nums[0];
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == diff) len++;
            else{
                len -= 2;
                if(len>0)
                ans += (len*(len+1))/2;
                
                diff = nums[i]-nums[i-1];
                len = 2;
            }
        }
        len -= 2;
        if(len>0)
            ans += (len*(len+1))/2;
        
        return ans;
    }
};