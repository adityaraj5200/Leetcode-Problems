class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n=grid.length,m=grid[0].length;

        for(int i=0;i<n;i++){
            sortDiagonal(grid,i,0,true);
        }

        for(int j=1;j<m;j++){
            sortDiagonal(grid,0,j,false);
        }

        return grid;
    }

    private void sortDiagonal(int[][] grid,int i,int j,boolean desc){
        int n=grid.length,m=grid[0].length;
        List<Integer> temp=new ArrayList<>();

        int x=i,y=j;
        while(x<n && y<m){
            temp.add(grid[x][y]);
            x++;y++;
        }

        if(desc){
            Collections.sort(temp,(a,b)->b-a);
        }else{
            Collections.sort(temp);
        }

        x=i;y=j;int k=0;
        while(x<n && y<m){
            grid[x][y]=temp.get(k++);
            x++;y++;
        }
    }
}
