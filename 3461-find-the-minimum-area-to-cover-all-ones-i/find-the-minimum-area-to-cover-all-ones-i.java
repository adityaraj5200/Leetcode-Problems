class Solution {
    public int minimumArea(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int firstRow=-1,lastRow=-1,firstCol=m,lastCol=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(firstRow == -1){
                        firstRow = i;
                    }
                    lastRow = i;

                    firstCol = Math.min(firstCol,j);
                    lastCol = Math.max(lastCol,j);
                }
            }
        }

        int side1 = lastRow-firstRow+1;
        int side2 = lastCol-firstCol+1;
        int answer = side1 * side2;

        return answer;        
    }
}