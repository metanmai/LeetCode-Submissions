// DFS Solution.

class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        if(x >= 0 and y >= 0 and
           x < m and y < n and grid[x][y] == 0)
        {
            grid[x][y] = 1;
            for(int i = 0; i < 4; i++)
                dfs(grid, x + dirs[i], y + dirs[i + 1]);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < m; i++)
        {
            if(grid[i][0] == 0)
                dfs(grid, i, 0);
            
            if(grid[i][n - 1] == 0)
                dfs(grid, i, n - 1);
        }
        
        for(int j = 0; j < n; j++)
        {
            if(grid[0][j] == 0)
                dfs(grid, 0, j);
            
            if(grid[m - 1][j] == 0)
                dfs(grid, m - 1, j);
        }
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0)
                {
                    dfs(grid, i, j);
                    islands++;
                }
        return islands;
    }
};