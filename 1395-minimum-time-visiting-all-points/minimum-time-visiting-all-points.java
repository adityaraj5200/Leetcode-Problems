class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0, n = points.length;
        for(int i=0;i<n-1;i++){
            ans += getDist(points[i], points[i+1]);
        }

        return ans;
    }

    private int getDist(int[] point1, int[] point2){
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];

        int deltaX = Math.abs(x1-x2);
        int deltaY = Math.abs(y1-y2);
        int maxDelta = Math.max(deltaX, deltaY);
        
        return maxDelta;
    }
}