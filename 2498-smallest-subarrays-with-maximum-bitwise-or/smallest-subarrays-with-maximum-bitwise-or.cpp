class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums){
        int n=nums.size();
        vector<int> nextSetBit(30,-1);
        vector<int> res(n);

        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<30;bit++){
                if(nums[i]&(1<<bit)){
                    nextSetBit[bit]=i;
                }
            }
            int maxReach=i;
            for(int bit=0;bit<30;bit++){
                maxReach=max(maxReach,nextSetBit[bit]);
            }
            res[i]=maxReach-i+1;
        }
        return res;
    }
};
