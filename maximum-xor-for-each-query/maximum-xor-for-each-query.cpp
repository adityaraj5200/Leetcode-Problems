class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result;
        int xorr = 0, n = nums.size();
        for(int &val: nums){
            xorr ^= val;
            int mask = 0, tempmaxbit = maximumBit;
            for(int i=0;i<maximumBit;i++){
                if((xorr & (1<<i)) == 0)
                    mask |= 1<<i;
            }
            result.push_back(mask);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};