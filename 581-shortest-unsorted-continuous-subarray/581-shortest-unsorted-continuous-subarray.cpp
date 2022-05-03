class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int st = -1, end = nums.size(), n = end;
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            if(nums[i] != vec[i]){
                st = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] != vec[i]){
                end = i;
                break;
            }
        }
        
        return st==-1 ? 0 : end-st+1;
    }
};