class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sumHappiness = 0;
        for(int i=happiness.length-1, j=0, toSubtract = 0;i>=0 && j<k;i--,j++,toSubtract++){
            sumHappiness += Math.max(0, happiness[i]-toSubtract);
        }

        return sumHappiness;
    }
}