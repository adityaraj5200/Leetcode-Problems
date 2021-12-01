class Solution {
public:
    int rob(vector<int>& nums) {
        int include = 0, exclude = 0;
        for(int &val: nums){
            int tempincl = include;
            include = max(include, exclude+val);
            exclude = max(tempincl, exclude);
        }
        return include;
    }
};