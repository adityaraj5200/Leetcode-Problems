// Time: O(log(min(n,m)))
// Space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for simpler binary search
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int n=nums1.size(),m=nums2.size();
        int total=n+m;
        int half=(total+1)/2;
        
        int low=0,high=n;
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=half-cut1;
            
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1==n)?INT_MAX:nums1[cut1];
            int r2=(cut2==m)?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                } else {
                    return max(l1,l2);
                }
            } 
            else if(l1>r2){
                high=cut1-1;
            } 
            else {
                low=cut1+1;
            }
        }
        return -1; // should never reach here
    }
};
