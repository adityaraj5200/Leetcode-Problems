class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        const int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        long long sum = 0;
        int MOD = 1e9+7;

        for (int i = 0; i < length; ++i) {
            int distLeft = i-left[i];
            int distRight = right[i]-i;
            int currVal = nums[i];
            sum = (sum + (1LL * currVal * distLeft * distRight))%MOD;
        }

        return (int)sum;
    }
};