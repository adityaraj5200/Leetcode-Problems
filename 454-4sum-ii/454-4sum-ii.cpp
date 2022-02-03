class Solution{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> freq;
        
        for(int &val: nums1)
            for(int &val2: nums2)
                freq[val+val2]++;
        
        int ans = 0;
        
        for(int &val: nums3)
            for(int &val2: nums4)
                ans += freq[-(val+val2)];
        
        return ans;
    }
};