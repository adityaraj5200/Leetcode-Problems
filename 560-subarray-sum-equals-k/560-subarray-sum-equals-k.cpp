class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> seen_freq;
        seen_freq[0] = 1;
        int currsum = 0, ans = 0;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            int req = currsum - k;
            if(seen_freq.find(req) != seen_freq.end()){
                ans += seen_freq[req];
            }
            
            seen_freq[currsum]++;
        }
        
        return ans;
    }
};