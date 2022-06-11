class Solution {
public:
    int helper(vector<int>& nums, int x){
        int n = nums.size(), i=0, j=n-1, leftsum=0, rightsum=0, ans=INT_MAX, elements=0;
        while(i<n && leftsum<x){
            leftsum += nums[i++];
            elements++;
        }
        i--;
        
        while(i>=0 && i<=j){
            if(leftsum+rightsum > x){
                leftsum -= nums[i--];
                elements--;
            }
            else if(leftsum+rightsum <= x){
                if(leftsum+rightsum == x)
                    ans = min(ans,elements);
                
                rightsum += nums[j--];
                elements++;
            }
        }
        
        return ans;
    }
    
    int minOperations(vector<int>& nums, int x) {
        int ans1 = helper(nums,x);
        reverse(nums.begin(),nums.end());
        int ans2 = helper(nums,x);
        
        return min(ans1,ans2)==INT_MAX ? -1 : min(ans1,ans2);
    }
};