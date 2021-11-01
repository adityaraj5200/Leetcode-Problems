class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), res = n;
        for(int i=0;i<n;i++){
            int index = abs(nums[i])-1;
            nums[index] *= -1;
            if(nums[index] > 0){
                res = abs(nums[i]);
                break;
            }
        }
        for(int &val: nums)
            val = abs(val);
        return res;
    }
};