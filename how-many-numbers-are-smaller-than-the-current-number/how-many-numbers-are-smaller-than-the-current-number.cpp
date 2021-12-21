class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){ 
        vector<int> freq(101,0),result(nums.size());
        for(int &val: nums)
            freq[val]++;
        
        for(int i = 1; i < 101; i++)
            freq[i] += freq[i - 1];
        
        for(int i = 0; i < nums.size(); i++)
            result[i] = nums[i]==0 ? 0 : freq[nums[i]-1];
        
        return result;
    }
};