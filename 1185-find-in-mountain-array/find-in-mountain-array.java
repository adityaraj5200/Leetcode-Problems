/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int low=0, high=n-1;
        while(low<high){
            int mid = (low+high)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                // We are in increasing part
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        int peak = low; // or high. as both are same at this point
        int ansIndex = -1;

        // Search in first half
        low = 0;
        high = peak;
        while(low<=high){
            int mid = (low+high)/2;
            int valueAtMid = mountainArr.get(mid);
            if(valueAtMid < target){
                low = mid+1;
            }
            else{
                if(valueAtMid==target){
                    ansIndex = mid;
                }
                high = mid-1;
            }
        }

        if(ansIndex != -1){
            return ansIndex;
        }


        // Search in second half
        low = peak;
        high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int valueAtMid = mountainArr.get(mid);
            if(valueAtMid > target){
                low = mid+1;
            }
            else{
                if(valueAtMid==target){
                    ansIndex = mid;
                }
                high = mid-1;
            }
        }

        return ansIndex;
    }
}