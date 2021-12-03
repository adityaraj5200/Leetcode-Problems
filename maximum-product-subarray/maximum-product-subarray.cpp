class Solution {
public:
    int helper(vector<int> &nums,int st,int end){
        int ans=INT_MIN,currProduct=1, i=st, j=end;
        while(i<=end){
            currProduct *= nums[i++];
            ans = max(ans, currProduct);   
        }
        currProduct = 1;
        while(j>=st){
            currProduct *= nums[j--];
            ans = max(ans, currProduct);
        }
        return ans;
    }
    
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(),nums.end()), n=nums.size(), i=0,j=0;
        while(j<n){
            while(j<n && nums[j]==0) j++;
            i=j;
            while(j<n && nums[j]!=0) j++;
            ans = max(ans,helper(nums,i,j-1));
        }
        return ans;
    }
};