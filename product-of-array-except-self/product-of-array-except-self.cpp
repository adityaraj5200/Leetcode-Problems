class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n), leftside(n) ,rightside(n);
        leftside[0] = nums[0], rightside[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
            leftside[i] = leftside[i-1]*nums[i];
        for(int i=n-2;i>=0;i--)
            rightside[i] = rightside[i+1]*nums[i];
        result[0] = rightside[1],result[n-1] = leftside[n-2];
        for(int i=1;i<n-1;i++)
            result[i] = leftside[i-1]*rightside[i+1];
        return result;
    }
};