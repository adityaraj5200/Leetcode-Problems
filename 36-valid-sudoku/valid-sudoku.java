class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<Integer>[] rowSet = new HashSet[9];
        Set<Integer>[] colSet = new HashSet[9];
        Set<Integer>[] boxSet = new HashSet[9];

        for(int i=0;i<9;i++){
            rowSet[i] = new HashSet<>();
            colSet[i] = new HashSet<>();
            boxSet[i] = new HashSet<>();
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int value = board[i][j]-'0';
                    if(rowSet[i].contains(value)) return false;
                    else rowSet[i].add(value);

                    if(colSet[j].contains(value)) return false;
                    else colSet[j].add(value);

                    int boxIndex = (i/3)*3 + (j/3);
                    if(boxSet[boxIndex].contains(value)) return false;
                    else boxSet[boxIndex].add(value);
                }
            }
        }
        
        return true;
    }
}