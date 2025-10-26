class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // EEEOEEOEEOEEOO
        int st=0,end=0,ans=0,cntOdd=0,n=nums.size(),firstOddInWindow=-1;
        if(k>n) return 0;

        while(end<n && cntOdd<k){
            if(nums[end]&1){
                cntOdd++;
                if(firstOddInWindow==-1){
                    firstOddInWindow = end;
                }
            }
            end++;
        }

        if(cntOdd<k) return 0;
        end--;

        // At this point, cntOdd==k
        while(st<n && end<n){
            // Handle for windows, cntOdd==k
            while(end<n && cntOdd==k){
                int contribution = firstOddInWindow-st+1;
                ans += contribution;

                end++;
                if(end<n){
                    if(nums[end]&1){
                        cntOdd++;
                    }
                }
            }

            // Now, cntOdd>k, so shrink the window
            while(cntOdd>k){
                if(nums[st]&1){
                    cntOdd--;
                }
                st++;
            }

            firstOddInWindow = st;
            while(nums[firstOddInWindow]%2==0){
                firstOddInWindow++;
            }
        }

        return ans;
    }
};