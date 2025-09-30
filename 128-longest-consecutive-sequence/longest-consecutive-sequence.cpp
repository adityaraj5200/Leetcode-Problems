class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> numsSet(nums.begin(),nums.end());
        int maxLen = 1;
        for(int& num: nums){
            if(numsSet.find(num-1) == numsSet.end()){
                int len = 1;
                while(numsSet.find(num+len) != numsSet.end()){
                    numsSet.erase(num+len);
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};