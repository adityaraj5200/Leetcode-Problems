class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, tempk = k;
        int i = 0, j = 0, n = nums.size();
        
        while(j<n){
            while(j<n){
                if(nums[j]==0){
                    if(tempk > 0)
                        tempk--;
                    else break;
                }
                j++;
            }
            
            ans = max(ans,j-i);
            
            while(i<n && tempk==0){
                if(nums[i++] == 0)
                    tempk++;
            }
        }
        return ans;
    }
};