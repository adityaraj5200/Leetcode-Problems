class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int totalApples = Arrays.stream(apple).sum();
        Arrays.sort(capacity);

        int count = 0, reminaing = totalApples, m = capacity.length;
        for(int i=m-1;i>=0 && reminaing>0;i--){
            reminaing -= capacity[i];
            count++;
        }

        return count;
    }
}