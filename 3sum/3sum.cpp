class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i=0;i<n-2;i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    int left = nums[j], right = nums[k];
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==left) j++;
                    while(j<k && nums[k]==right) k--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        
        return result;
    }
};