class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minval = INT_MAX,sum=0;
        for(int &val: nums)
            minval = min(minval,sum += val);
        return minval <= 0 ? -minval + 1 : 1;
    }
};