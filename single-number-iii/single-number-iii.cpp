class Solution{
public:
    vector<int> singleNumber(vector<int>& nums){
        int bitxor = 0,a = 0,b = 0,shifts = 0;
        for(int &val: nums)
            bitxor ^= val;
        while((bitxor&1) == 0){
            shifts++;
            bitxor >>= 1;
        }
        bitxor = 1<<shifts;
        for(int &val: nums)
            if(val & bitxor) a ^= val;
            else b ^= val;
        return {a,b};
    }
};