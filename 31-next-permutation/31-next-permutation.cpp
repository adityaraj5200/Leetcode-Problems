class Solution {
public:
    void nextPermutation(vector<int>& nums){
        const int n = nums.size();
        int firstdecIdx = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                firstdecIdx = i;
                break;
            }
        }
        
        if(firstdecIdx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int swappingIdx = firstdecIdx+1;
        while(swappingIdx<n && nums[swappingIdx] > nums[firstdecIdx]){
            swappingIdx++;
        }
        swappingIdx--;
        
        swap(nums[swappingIdx],nums[firstdecIdx]);
        
        int i=firstdecIdx+1, j=n-1;
        while(i<j)
            swap(nums[i++], nums[j--]);
    }
};