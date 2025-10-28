class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefixSum = nums;
        vector<int> suffixSum = nums;
        int n = nums.size();
        for(int i=1;i<n;i++){
            prefixSum[i] += prefixSum[i-1];
            suffixSum[n-i-1] += suffixSum[n-i];
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(prefixSum[i] == suffixSum[i]){
                    ans += 2;
                }
                else if(abs(prefixSum[i] - suffixSum[i])==1){
                    ans++;
                }
            }
        }

        return ans;
    }
};