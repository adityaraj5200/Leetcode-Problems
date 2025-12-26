class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int penaltyIfOpen[] = new int[n], penaltyCnt = 0;

        for(int i=0;i<n;i++){
            if(customers.charAt(i)=='N'){
                penaltyCnt++;
            }
            penaltyIfOpen[i] = penaltyCnt;
        }

        int minPenalty = penaltyCnt, idxMinPenalty = n;
        int penaltyIfClose = 0;
        for(int i=n-1;i>=0;i--){
            if(customers.charAt(i)=='Y'){
                penaltyIfClose++;
            }

            int penaltyAtThisPoint = penaltyIfClose + (i>0 ? penaltyIfOpen[i-1] : 0);
            if(penaltyAtThisPoint <= minPenalty){
                minPenalty = penaltyAtThisPoint;
                idxMinPenalty = i;
            }
        }

        return idxMinPenalty;
    }
}