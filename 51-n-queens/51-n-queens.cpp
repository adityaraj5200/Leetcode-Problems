class Solution {
public:
    vector<vector<string>> result;
    vector<string> curr;
    
    bool isvalidpos(int row,int col,int n){
        for(int i=0,j=0;i<n;i++,j++)
            if(curr[row][j]=='Q' || curr[i][col]=='Q')
                return false;
        
        for(int i=row,j=col; i>=0 && j<n ; i--,j++)
            if(curr[i][j]=='Q')
                return false;
        
        for(int i=row,j=col; i<n && j>=0 ; i++,j--)
            if(curr[i][j]=='Q')
                return false;
            
        for(int i=row,j=col; i>=0 && j>=0 ; i--,j--)
            if(curr[i][j]=='Q')
                return false;
        
        for(int i=row,j=col; i<n && j<n ; i++,j++)
            if(curr[i][j]=='Q')
                return false;
        
        return true;
    }
    
    void helper(int i,int n){
        if(i==n){
            result.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            if(isvalidpos(i,j,n)){
                curr[i][j] = 'Q';
                helper(i+1,n);
                curr[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        curr = vector<string>(n,str);
        helper(0,n);
        return result;
    }
};