class Solution {
    public int numberOfWays(String corridor) {
        long ans = 1, placeholders = 0, MOD = (long)1e9 + 7;
        int seatCnt = 0;
        for(char ch: corridor.toCharArray()){
            if(ch=='S'){
                seatCnt++;
                if(seatCnt==3){
                    ans = (ans*placeholders)%MOD;
                    seatCnt = 1;
                    placeholders=0;
                }
            }

            if(seatCnt==2){
                placeholders++;
            }
        }

        return seatCnt<2 ? 0 : (int)ans;
    }
}