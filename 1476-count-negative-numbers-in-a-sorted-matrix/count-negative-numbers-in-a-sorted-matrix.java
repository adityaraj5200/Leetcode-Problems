class Solution {
    public int countNegatives(int[][] grid) {
        int n=grid.length,m=grid[0].length;
        int row=0,col=m-1;
        int cnt = 0;
        while(row<n && col>=0){
            if(grid[row][col]<0){
                cnt += n-row;
                col--;
            }
            else{
                row++;
            }
        }

        return cnt;
    }
}


/*
    5 4 3 2  0  -1 -2 -4 -5
          -1 -2 -4 -5  -7 -9 

 */