class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, ans = 0;
        for(int &val: nums){
            if(val==1)
                ans = max(ans, ++curr);            
            else curr = 0;
        }
        
        return ans;
    }
};