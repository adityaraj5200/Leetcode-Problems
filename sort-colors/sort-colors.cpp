class Solution{
public:
    void sortColors(vector<int>& nums) {
        int l=0,n=nums.size(),r=nums.size()-1,i=0;
        while(i<=r){
            if(nums[i] == 0) swap(nums[i++],nums[l++]);
            else if(nums[i] == 2) swap(nums[i],nums[r--]);
            else i++;
        }
    }
};