class Solution {
public:
    // all 4 & 8- direction move
    int dx4[4]={1,0,-1,0}, dy4[4]={0,1,0,-1}, n, m;
    
    bool isValidPos(int &i,int &j,int &n,int &m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    bool helper(vector<vector<char>>& board,int i,int j,vector<vector<bool>> &vis,string &word,int k){
        if(k==word.length()) return true;
        if(!isValidPos(i,j,n,m) || board[i][j] != word[k] || vis[i][j]) return false;
        vis[i][j] = true;
        bool flag = false;
        for(int d=0;d<4;d++){
            int x = i+dx4[d], y = j+dy4[d];
            if(helper(board,x,y,vis,word,k+1))
                return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(helper(board,i,j,vis,word,0))
                    return true;
        }
        return false;
    }
};