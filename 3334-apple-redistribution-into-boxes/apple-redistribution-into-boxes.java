class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int totalApples = Arrays.stream(apple).sum();
        Arrays.sort(capacity);

        int count = 0;
        for(int i=capacity.length-1;i>=0;i--){
            totalApples -= capacity[i];
            count++;
            if(totalApples <= 0){
                break;
            }
        }

        return count;
    }
}