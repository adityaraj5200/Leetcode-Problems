class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i=0;i<32;i++){
            int set=0;
            for(int &val: nums){
                if(val&1) set++;
                val >>= 1;
            }
            cnt += set*(n-set);
        }
        return cnt;
    }
};