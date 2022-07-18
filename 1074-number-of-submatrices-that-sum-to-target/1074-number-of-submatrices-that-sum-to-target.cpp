class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                matrix[i][j] += matrix[i][j-1];
        
        int ans = 0;
        
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                
                int sum = 0;
                unordered_map<int,int> seen = {{0,1}};
                
                for(int row=0;row<n;row++){
                    sum += matrix[row][c2] - (c1>0 ? matrix[row][c1-1] : 0);
                    
                    if(seen.find(sum-target) != seen.end())
                        ans += seen[sum-target];
                    
                    seen[sum]++;
                }
            }
        }
                
        return ans;
    }
};