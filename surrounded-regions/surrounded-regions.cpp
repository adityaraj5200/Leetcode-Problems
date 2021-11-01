class Solution {
public:
    int n,m;
    vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
    void bfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || i==n || j<0 || j==m) return;
        if(board[i][j] != 'O') return;
        board[i][j] = '.';
        for(int k=0;k<4;k++)
            bfs(board,i+dx[k],j+dy[k]);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            bfs(board,i,0);
            bfs(board,i,m-1);
        }
        for(int j=0;j<m;j++){
            bfs(board,0,j);
            bfs(board,n-1,j);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};