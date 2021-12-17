class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        rowwise,colwise,n,m,ans = [max(row) for row in grid], [max(col) for col in zip(*grid)], len(grid), len(grid[0]), 0
        
        for i in range(n):
            for j in range(m):
                ans += min(rowwise[i],colwise[j])-grid[i][j]
        
        return ans