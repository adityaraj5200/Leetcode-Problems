class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowAllZero = false, firstColAllZero = false;
        int n = matrix.size(), m = matrix[0].size();
        
        for(int j=0;j<m;j++){
            if(matrix[0][j] == 0){
                firstRowAllZero = true;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0] == 0){
                firstColAllZero = true;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int j=1;j<m;j++)
            if(matrix[0][j]==0){
                for(int i=1;i<n;i++){
                    matrix[i][j] = 0;
            }
        }
        
        if(firstRowAllZero)
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;
        
        if(firstColAllZero)
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
    }
};