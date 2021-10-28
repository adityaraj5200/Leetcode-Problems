class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length(), carry = 0;
        string res(max(n,m),'0');
        for(int i=m-1,j=n-1 ; max(i,j)>=0 ; i--,j--){
            int sum = (j>=0?a[j]-'0':0) + (i>=0?b[i]-'0':0) + carry;
            if(sum == 0) res[max(i,j)] = '0', carry = 0;
            else if(sum == 1) res[max(i,j)] = '1', carry = 0;
            else if(sum == 2) res[max(i,j)] = '0', carry = 1;
            else if(sum == 3) res[max(i,j)] = '1', carry = 1;
        }
        return carry ? "1"+res : res;
    }
};