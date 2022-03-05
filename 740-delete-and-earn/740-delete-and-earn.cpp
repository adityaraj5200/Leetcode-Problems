class Solution{
public:
    int deleteAndEarn(vector<int>& nums){
        const int maxN = 1e4;
        vector<int> freq(maxN+1,0);
        for(int val: nums) 
            freq[val]++;
        
        int inc = freq[1];
        int exc = 0;
        int inc_prev=inc,exc_prev=exc;
        
        for(int val=2;val<=maxN;val++){
            inc = freq[val]*val + exc_prev;
            exc = max(inc_prev,exc_prev);
            inc_prev = inc;
            exc_prev = exc;
        }
        
        return max(inc,exc);
    }
};
