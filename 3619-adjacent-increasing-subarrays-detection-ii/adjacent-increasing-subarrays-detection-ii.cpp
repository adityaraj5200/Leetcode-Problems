class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0, curr = 0, prev = 0, lastNum = INT_MIN;
        for(int& val: nums){
            if(val > lastNum){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }

            ans = max({ans, min(curr,prev), curr/2});
            lastNum = val;
        }

        return ans;
    }
};