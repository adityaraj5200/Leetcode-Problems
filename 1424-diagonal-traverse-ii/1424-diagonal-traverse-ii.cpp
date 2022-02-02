class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums){
        int sz = 0;
        map<int,vector<int>> mp;
        int maxkey = 0;
        for(int i=nums.size()-1;i>=0;i--){
            sz += nums[i].size();
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
                maxkey = max(maxkey,i+j);
            }
        }
        
        vector<int> ans(sz);
        int k = 0;
        for(int key=0;key<=maxkey;key++)
            for(int &val: mp[key])
                ans[k++] = val;
        
        return ans;
    }
};