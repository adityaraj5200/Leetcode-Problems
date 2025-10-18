class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lastVal = INT_MIN, distinct = 0;
        for(int& num: nums){
            int newNum = max(num-k, lastVal+1); // Lower bound is (num-k)
            newNum = min(newNum, num+k); // Upper bound is (num+k)
            if(newNum != lastVal){
                distinct++;
            }
            lastVal = newNum;
            num = newNum;
        }

        return distinct;
    }
};