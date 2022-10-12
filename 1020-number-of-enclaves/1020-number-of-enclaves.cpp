class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int m, n;
    
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        if(x >= 0 and y >= 0 and x < m and y < n and grid[x][y])
        {
            grid[x][y] = 0;
            
            for(int i = 0; i < 4; i++)
                dfs(grid, x + dir[i], y + dir[i + 1]);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int totalArea = 0, i, j;
        
        for(i = 0; i < m; i++)
        {
            if(grid[i][0])
                dfs(grid, i, 0);
            
            if(grid[i][n - 1])
                dfs(grid, i, n - 1);
        }
        
        for(j = 0; j < n; j++)
        {
            if(grid[0][j])
                dfs(grid, 0, j);
            
            if(grid[m - 1][j])
                dfs(grid, m - 1, j);
        }
        
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                totalArea += grid[i][j];
        
        return totalArea;
    }
};