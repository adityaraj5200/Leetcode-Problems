// Time Complexity: O(m * n * 4^L)
// Space Complexity: O(L) — recursion stack depth (L = length of the word)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board,const string& word,int i,int j,int k){
        if(k==word.size()) return true;
        int m=board.size(),n=board[0].size();
        if(i<0||j<0||i>=m||j>=n||board[i][j]!=word[k]) return false;

        char temp=board[i][j];
        board[i][j]='#'; // mark visited

        bool found=dfs(board,word,i+1,j,k+1)
                 || dfs(board,word,i-1,j,k+1)
                 || dfs(board,word,i,j+1,k+1)
                 || dfs(board,word,i,j-1,k+1);

        board[i][j]=temp; // backtrack
        return found;
    }
};
