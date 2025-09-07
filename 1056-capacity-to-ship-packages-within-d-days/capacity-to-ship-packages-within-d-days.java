class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int sum = 0;
        for(int weight: weights){
            sum += weight;
        }

        int low=0, high=sum;
        while(low<high){
            int mid=(low+high)/2;
            if(isPossible(weights,days,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }

    private boolean isPossible(int[] weights,int days, int weightCapacity){
        int daysRequired = 0, weightSum = (int)1e9;
        for(int weight: weights){
            if(weight > weightCapacity){
                return false;
            }

            weightSum += weight;
            if(weightSum > weightCapacity){
                weightSum = weight;
                daysRequired++;
                if(daysRequired>days){
                    return false;
                }
            }
        }

        return true;
    }
}