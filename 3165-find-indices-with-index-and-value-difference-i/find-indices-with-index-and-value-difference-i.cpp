class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for(int i=0,j=indexDifference,behindMinIndex=0,behindMaxIndex=0;j<nums.size();i++,j++){
            if(nums[i]<nums[behindMinIndex]){
                behindMinIndex = i;
            }
            if(nums[i]>nums[behindMaxIndex]){
                behindMaxIndex = i;
            }

            int diff1 = abs(nums[behindMinIndex]-nums[j]);
            int diff2 = abs(nums[behindMaxIndex]-nums[j]);

            int currValDiff = max(diff1, diff2);



            if(currValDiff >= valueDifference){
                // found the answer
                if(diff1 >= valueDifference){
                    return {behindMinIndex,j};
                }
                else{
                    return {behindMaxIndex,j};
                }

            }
        }

        return {-1,-1};
    }
};