class Solution {
public:
    int nextBeautifulNumber(int n) {
        n++;
        while(!isBeautifulNumber(n)){
            n++;
        }

        return n;
    }
private:
    int isBeautifulNumber(int x){
        vector<int> digitCnt(10,0);
        while(x > 0){
            int d = x%10;
            if(d==0){
                return false;
            }

            x /= 10;
            digitCnt[d]++;
        }

        for(int i=1;i<10;i++){
            if(digitCnt[i]!=0 && digitCnt[i] != i){
                return false;
            }
        }

        return true;
    }
};