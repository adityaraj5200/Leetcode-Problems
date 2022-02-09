class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,i=0,j=0;
        const int n = nums.size();
        
        while(i<n && j<n){
            int diff = nums[j]-nums[i];
            
            if(i==j)
                j++;
            else if(diff < k)
                j++;
            else if(diff > k)
                i++;
            else{
                ans++;
                
                int curr = nums[i];
                while(i<n && nums[i]==curr)
                    i++;
                
                curr = nums[j];
                while(j<n && nums[j]==curr)
                    j++;
            }
        }
        return ans;
    }
};