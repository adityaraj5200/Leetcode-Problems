class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1,ansIndex = nums.size();
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] < target)
                low = mid+1;
            else{
                ansIndex = mid;
                high = mid-1;
            }
        }
        return ansIndex;
    }
};