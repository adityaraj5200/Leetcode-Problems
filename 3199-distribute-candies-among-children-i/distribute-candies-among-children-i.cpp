class Solution {
public:
    int distributeCandies(int n, int limit) {
        return solve(1,n,limit);
    }
private:
    int solve(int childNum,int n,int limit){
        if(childNum==4) return n==0;

        int ways=0;
        for(int i=0;i<=min(n,limit);i++){
            ways += solve(childNum+1,n-i,limit);
        }
        return ways;
    }
};