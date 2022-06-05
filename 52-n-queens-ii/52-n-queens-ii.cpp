class Solution {
public:
    int ans;
    vector<string> curr;
    int N;
    map<int,bool> row,diaglu,diagld; // lu - left up, ld - left down;
    
    void helper(int currcol){
        if(currcol==N){
            ans++;
            return;
        }
        
        int j = currcol;
        for(int i=0;i<N;i++){
            if(!row[i] && !diaglu[i-j] && !diagld[i+j]){
                // cout<<"here"<<endl;
                row[i] = diaglu[i-j] = diagld[i+j] = true;
                curr[i][j] = 'Q';
                
                helper(j+1);
                
                curr[i][j] = '.';
                row[i] = diaglu[i-j] = diagld[i+j] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        string s(n,'.');
        curr.resize(n,s);
        
        ans = 0;
        N = n;
        
        for(int i=-2*N; i<2*N;i++){
            row[i] = diaglu[i] = diagld[i] = false;
        }
        
        helper(0);
        
        return ans;
    }
};