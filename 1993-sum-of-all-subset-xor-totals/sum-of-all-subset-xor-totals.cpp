class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumXORTotal = 0;
        solve(0,nums,0,sumXORTotal);
        return sumXORTotal;
    }
private:
    void solve(int idx,vector<int>& nums,int currXOR,int& sumXORTotal){
        if(idx==nums.size()){
            sumXORTotal += currXOR;
            return;
        }

        solve(idx+1,nums,currXOR^nums[idx],sumXORTotal);
        solve(idx+1,nums,currXOR,sumXORTotal);
    }
};