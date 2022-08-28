class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        
        for(int col=0,i,j;col<m;col++){
            priority_queue<int,vector<int>,greater<int>> pq;
            
            i=0,j=col;
            while(i<n && j<m){
                pq.push(mat[i++][j++]);
            }
            
            i=0,j=col;
            while(i<n && j<m){
                mat[i++][j++] = pq.top();
                pq.pop();
            }
        }
        
        for(int row=1,i,j;row<n;row++){
            priority_queue<int,vector<int>,greater<int>> pq;
            
            i=row,j=0;
            while(i<n && j<m){
                pq.push(mat[i++][j++]);
            }
            
            i=row,j=0;
            while(i<n && j<m){
                mat[i++][j++] = pq.top();
                pq.pop();
            }
        }
        
        return mat;
    }
};