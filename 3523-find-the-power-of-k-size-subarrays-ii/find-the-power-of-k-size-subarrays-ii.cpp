class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int runningConsecutive = 0, last = nums[0]-1, n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            runningConsecutive = (nums[i]==last+1) ? runningConsecutive+1 : 1;
            if(i>=k-1){
                int toAdd = runningConsecutive>=k ? nums[i] : -1;
                ans.push_back(toAdd);
            }
            last = nums[i];
        }

        return ans;
    }
};