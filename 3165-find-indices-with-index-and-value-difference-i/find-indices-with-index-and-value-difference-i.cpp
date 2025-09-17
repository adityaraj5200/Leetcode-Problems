// Time Complexity: O(n)  (single pass over array)
// Space Complexity: O(1) (only a few variables used)

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=nums.size();
        int minIdx=0,maxIdx=0;

        for(int i=0,j=indexDifference;j<n;i++,j++){
            if(nums[i]<nums[minIdx]) minIdx=i;
            if(nums[i]>nums[maxIdx]) maxIdx=i;

            if(abs(nums[j]-nums[minIdx])>=valueDifference)
                return {minIdx,j};
            if(abs(nums[j]-nums[maxIdx])>=valueDifference)
                return {maxIdx,j};
        }

        return {-1,-1};
    }
};
