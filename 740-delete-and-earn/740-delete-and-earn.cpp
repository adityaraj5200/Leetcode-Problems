class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        for(int &val: nums){
            freq[val]++;
        }
        
        int inc = freq[1]; //include
        int exc = 0; // exclude
        int previnc = inc, prevexc = exc; // previous include, exclude;
        
        for(int val=2;val<=1e4;val++){
            inc = val*freq[val]+prevexc;
            exc = max(previnc, prevexc);
            
            previnc = inc;
            prevexc = exc;
        }
        
        return max(inc,exc);
    }
};