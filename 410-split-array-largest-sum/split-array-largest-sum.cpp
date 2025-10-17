// Time Complexity: O(n * log(sum(nums) - max(nums)))
// Space Complexity: O(1)

class Solution {
public:
    bool canSplit(const vector<int>& nums, long long maxAllowed, int k) {
        long long currSum = 0;
        int parts = 1; // start with one subarray
        
        for(int x : nums) {
            if(currSum + x > maxAllowed) { 
                parts++;           // start new subarray
                currSum = x;
                if(parts > k) return false;
            } else {
                currSum += x;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(canSplit(nums, mid, k)) {
                high = mid;       // try smaller max sum
            } else {
                low = mid + 1;    // need larger max sum
            }
        }
        return (int)low;
    }
};
