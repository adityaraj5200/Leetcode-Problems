class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int runningSum = 0, ans = 0;
        for(int& num: nums){
            runningSum += num;
            int counterSum = runningSum-k;
            if(mp.find(counterSum) != mp.end()){
                ans += mp[counterSum];
            }
            mp[runningSum]++;
        }

        return ans;
    }
};