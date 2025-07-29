class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int firstDip=n-2;
        // 4765321 will get changed to
        // 5123467
        while(firstDip>=0 && nums[firstDip]>=nums[firstDip+1]){
            firstDip--;
        }

        int minGreater = firstDip+1;
        if(firstDip>=0){
            while(minGreater<n && nums[minGreater]>nums[firstDip]){
                minGreater++;
            }
            minGreater--;

            if(minGreater<n & firstDip>=0){
                swap(nums[firstDip], nums[minGreater]);
            }
        }

        int revSt=firstDip+1, revEnd=n-1;
        while(revSt<revEnd){
            swap(nums[revSt++],nums[revEnd--]);
        }        
    }
};