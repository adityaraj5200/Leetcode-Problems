class Solution{
public:
    int lastStoneWeightII(vector<int>& stones){
        // const int MAX_NUM = 3001, MAX_ARRAY_SIZE = 3001;
        const int sum = accumulate(stones.begin(),stones.end(),0);
        
        bitset<3001+1> bits(1);
        
        for (auto &val : stones){
            bits |= bits << val;
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<=sum;i++){
            if(bits[i]){
                ans = min(ans, abs(i-(sum-i)));
            }
        }
        
        return ans;
    }
};