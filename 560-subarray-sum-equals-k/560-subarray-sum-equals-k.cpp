class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp = {{0,1}};
        int sum = 0, ans = 0;
        for(int &val: nums){
            sum += val;
            int find = sum-k;
            if(mp.find(find) != mp.end())
                ans += mp[find];
            
            mp[sum]++;
        }
        
        return ans;
    }
};