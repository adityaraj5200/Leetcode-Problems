// TC: O(log n) — where n is input integer value (since bit-length ~ log₂n)  
// SC: O(1)
// Approach: Recursively reduce n by using the largest power of two ≤ n.  
//   Let x = 2^k ≤ n. We flip bits to transform n → n ^ (x | (x>>1)) in one operation,  
//   then recursively solve for that result, and add (x-1) extra operations because turning 2^k → 0 takes 2^(k+1)-1 ops.  
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        int x=1;
        while(x*2 <= n) x*=2;
        return minimumOneBitOperations(n ^ (x | (x>>1))) + 1 + (x - 1);
    }
};
