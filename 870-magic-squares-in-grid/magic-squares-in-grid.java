class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length, m = grid[0].length, cnt = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(check(grid,i,j)){
                    cnt++;
                }
            }
        }

        return cnt;
    }

    private boolean check(int[][] grid, int row, int col){
        int reqSum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int sum = 0;
        Set<Integer> set = new HashSet<>();
        for(int rowNum=row;rowNum<=row+2;rowNum++){
            sum = 0;
            for(int colNum=col;colNum<=col+2;colNum++){
                sum += grid[rowNum][colNum];
                set.add(grid[rowNum][colNum]);
            }
            if(sum != reqSum){
                return false;
            }
        }

        for(int colNum=col;colNum<=col+2;colNum++){
            sum = 0;
            for(int rowNum=row;rowNum<=row+2;rowNum++){
                sum += grid[rowNum][colNum];
            }
            if(sum != reqSum){
                return false;
            }
        }

        int diagSum = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int antiDiagSum = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];

        if((sum != diagSum) || (sum != antiDiagSum)){
            return false;
        }

        if(set.size() != 9){
            return false;
        }
        for(int i=1;i<=9;i++){
            if(!set.contains(i)){
                return false;
            }
        }


        return true;
    }
}