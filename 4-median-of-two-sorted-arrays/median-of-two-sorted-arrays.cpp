// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int> &A = nums1, &B = nums2;
        int m = A.size(), n = B.size();
        // ensure A is the smaller array
        if (m > n) return findMedianSortedArrays(B, A);
        
        int total = m + n;
        int half = (total + 1) / 2;
        
        int l = 0, r = m;
        while(l <= r) {
            int i = (l + r) / 2;          // number of elements taken from A
            int j = half - i;             // number of elements taken from B
            
            int Aleft = (i == 0 ? INT_MIN : A[i-1]);
            int Aright = (i == m ? INT_MAX : A[i]);
            int Bleft = (j == 0 ? INT_MIN : B[j-1]);
            int Bright = (j == n ? INT_MAX : B[j]);
            
            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if (total % 2 == 1) {
                    // odd number of total elements
                    return (double) max(Aleft, Bleft);
                } else {
                    // even number of total elements
                    return ((double) max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                // too many taken from A, move left
                r = i - 1;
            }
            else {
                // Aleft <= Bright but Bleft > Aright => too few taken from A
                l = i + 1;
            }
        }
        
        return -1; // control should never reach here
    }
};
