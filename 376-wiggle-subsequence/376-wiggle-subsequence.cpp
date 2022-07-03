class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        int up = 1, down = 1;
        // up contains the length of the longest wiggle subsequence when the last value of our subsequence went up i.e. last value was greater than the second last value of the subsequence
        // down contains the length of the longest wiggle subsequence when the last value of our subsequence went down i.e. last value was smaller than the second last value of the subsequence
        
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1])
                up = down + 1;
            else if(nums[i] < nums[i-1])
                down = up + 1;
        }
        
        return max(up, down);
    }
};