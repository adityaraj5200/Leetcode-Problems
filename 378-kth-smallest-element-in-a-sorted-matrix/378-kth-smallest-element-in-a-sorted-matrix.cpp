class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        vector<int> indices(n,0);
        int minValue, minRow, ans;
        while(k--){
            minValue = INT_MAX;
            minRow = 0;
            for(int i=0;i<n;i++){
                if(indices[i]!=-1 && matrix[i][indices[i]]<minValue){
                    minValue = matrix[i][indices[i]];
                    minRow = i;
                }
            }
            
            ans = matrix[minRow][indices[minRow]];
            indices[minRow]++;
            if(indices[minRow]==n)
                indices[minRow] = -1;
        }
        
        return ans;
    }
};