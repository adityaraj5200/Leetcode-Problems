class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = 1000000000 + 7;
        for(int j=2;j<=n;j++){
            long a_next = (e+i+u)%mod;
            long e_next = (a+i)%mod;
            long i_next = (e+o)%mod;
            long o_next = (i)%mod;
            long u_next = (i+o)%mod;
            
            a = a_next;
            e = e_next;
            i = i_next;
            o = o_next;
            u = u_next;            
        }
        
        return (a+e+i+o+u)%mod;
    }
};