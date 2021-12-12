class Solution {
public:
    bool canPartition(vector<int>& nums){
        const int MAX_NUM = 100, MAX_ARRAY_SIZE = 200, sum = accumulate(nums.begin(),nums.end(),0);
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        if(sum&1)
            return false;
        for (auto &val : nums){
            bits |= bits << val;
            if(bits[sum/2])
                return true;
        }
        return bits[sum / 2];
    }
};