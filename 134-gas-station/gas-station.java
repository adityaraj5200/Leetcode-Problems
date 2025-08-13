class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalGas=0, totalCost=0, potentialStartIndex=0, gasInTank=0;
        for(int i=0;i<gas.length;i++){
            gasInTank += gas[i] - cost[i];
            if(gasInTank<0){
                potentialStartIndex = i+1;
                gasInTank = 0;
            }

            totalGas += gas[i];
            totalCost += cost[i];
        }

        return (totalGas<totalCost ? -1 : potentialStartIndex);
    }
}