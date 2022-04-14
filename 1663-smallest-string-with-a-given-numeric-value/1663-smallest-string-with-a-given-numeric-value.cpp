class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k -= n;
        int i=n-1;
        while(k>0){
            int change = min(25, k);
            ans[i--] += change;
            k -= change;
        }
        
        return ans;
    }
};