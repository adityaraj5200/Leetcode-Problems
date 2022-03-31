class Solution {
public:
    bool check(int sumLimit, vector<int>& nums, int m){
        int numSubarrays = 1, totalSum = 0;
        for(int &val: nums){
            if(val > sumLimit)
                return false;
            
            if(totalSum + val > sumLimit){
                numSubarrays++;
                totalSum = 0;
            }
            totalSum += val;
        }
        
        return numSubarrays <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int ans = INT_MAX;
        int low = 0, high = 1e9;
        while(low <= high){
            int mid = (low+high)/2; // mid is the possible largest sum
            if(check(mid,nums,m)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};