class Solution {
public:
    int search(vector<int>& nums, int target){
        const int n = nums.size();
        int low = 0, high = n-1, pivot = 0;
        while(low<high){
            int mid = (low+high)>>1;
            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        pivot = low;
        
        // cout<<"pivot = "<<pivot<<endl;
        
        low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)>>1;
            int realmid = (mid+pivot)%n;
            if(nums[realmid] < target)
                low = mid+1;
            else if(nums[realmid] > target)
                high = mid-1;
            else return realmid;
        }
        return -1;
    }
};