class Solution {
public:
    int n,m,size;
    int getKth(vector<int>& nums1,vector<int>& nums2,int k){
        // this function will give me the kth smallest element from the nums1 and num2 in logn time
        int low = 0, high = k;
        while(low<=high){
            int mid = (low+high)/2;
            int take1 = mid;
            int take2 = k-mid;
            
            if(take2 > m){
                int exceed = take2-m;
                take2 -= exceed;
                take1 += exceed;
            }
            
            int last_covered_in_1 = take1==0 ? INT_MIN : nums1[take1-1];
            int last_covered_in_2 = take2==0 ? INT_MIN : nums2[take2-1];
            int last_uncovered_in_1 = take1==n ? INT_MAX : nums1[take1];
            int last_uncovered_in_2 = take2==m ? INT_MAX : nums2[take2];
            
            int max_covered = max(last_covered_in_1,last_covered_in_2);
            int min_uncovered = min(last_uncovered_in_1,last_uncovered_in_2);
            if(max_covered <= min_uncovered){
                // Yeah! we got the answer!!!!!
                return max_covered;
            }
            else if(last_covered_in_1 > last_uncovered_in_2){
                high = mid-1;
            }
            else if(last_covered_in_2 > last_uncovered_in_1){
                low = mid+1;
            }
        }
        
        return -1; // Control will never reach here though
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        size = n+m;
        if(n<m){
            nums1.swap(nums2);
            swap(n,m);
        }
        
        double ans = 0.0;
        if(size&1){
            // cout<<"here ";
            ans += getKth(nums1,nums2,(size/2)+1);
        }
        else{
            ans += getKth(nums1,nums2,(size/2)+1);
            ans += getKth(nums1,nums2,(size/2));
            ans /= 2.0;
        }
        
        return ans;
    }
};