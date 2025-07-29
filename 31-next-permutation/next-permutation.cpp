// Basically iterate from the right most to left side and find the first Dip
// Swap this first Dip with the guy who is on right side and just greater than the first Dip guy
// Reverse whatever is on the right side of the first Dip guy
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), firstDip=n-2;
        while(firstDip>=0 && nums[firstDip]>=nums[firstDip+1]){
            firstDip--;
        }

        if(firstDip>=0){
            int justLarger = n-1;
            while(nums[justLarger]<=nums[firstDip]){
                justLarger--;
            }

            swap(nums[firstDip], nums[justLarger]);
        }

        reverse(nums.begin()+firstDip+1, nums.end());
    }
};