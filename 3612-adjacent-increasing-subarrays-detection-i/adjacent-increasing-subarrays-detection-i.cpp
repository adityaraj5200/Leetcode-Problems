class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 0, curr = 0, lastNum = 1e9;
        for(int& val: nums){
            if(val > lastNum){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }

            if(curr>=2*k || (prev>=k && curr>=k)){
                return true;
            }

            lastNum = val;
        }

        return false;
    }
};