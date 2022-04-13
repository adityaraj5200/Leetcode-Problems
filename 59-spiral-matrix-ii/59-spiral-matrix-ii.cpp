class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int val = 1, direction = 0, i, j;
        
        while(top<=bottom && left<=right){
            switch(direction){
                case 0:
                    for(int j=left;j<=right;j++)
                        ans[top][j] = val++;
                    top++;
                    direction++;
                    break;
                    
                case 1:
                    for(int i=top;i<=bottom;i++)
                        ans[i][right] = val++;
                    right--;
                    direction++;
                    break;
                    
                case 2:
                    for(int j=right;j>=left;j--)
                        ans[bottom][j] = val++;
                    bottom--;
                    direction++;
                    break;
                    
                case 3:
                    for(int i=bottom;i>=top;i--)
                        ans[i][left] = val++;
                    left++;
                    direction = 0;
                    break;
            }
        }
        
        return ans;
    }
};