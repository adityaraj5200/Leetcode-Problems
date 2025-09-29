class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0, k = 0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i&1){
                // neg
                while(nums[neg]>0) neg++;
                ans[k++] = nums[neg++];
            }
            else{
                // pos
                while(nums[pos]<=0) pos++;
                ans[k++] = nums[pos++];
            }
        }

        return ans;
    }
};