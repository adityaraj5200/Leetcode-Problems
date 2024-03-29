class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, curr = 0;
        while(curr<=right){
            if(nums[curr]==0){
                swap(nums[left++],nums[curr++]);
            }
            else if(nums[curr]==1){
                curr++;
            }
            else if(nums[curr]==2){
                swap(nums[right--],nums[curr]);
            }
        }
    }
};