class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int c2 = i*i + j*j;
                int val = sqrt(c2);

                if(val*val==c2 && c2 <= n*n){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};