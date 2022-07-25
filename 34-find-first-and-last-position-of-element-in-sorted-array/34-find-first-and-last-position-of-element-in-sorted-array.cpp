class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int getIdx = -1, low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid] < target) low = mid+1;
            else if(nums[mid] > target) high = mid-1;
            else{
                getIdx = mid;
                break;
            }
        }
        
        if(getIdx == -1) return {-1,-1};
        
        int st = getIdx, end = getIdx;
        
        low = 0, high = getIdx;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                st = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        low = getIdx, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                end = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return {st,end};
        
    }
};