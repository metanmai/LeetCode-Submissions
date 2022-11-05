// DFS Solution.

class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        int area = 1;
        
        if(x >= 0 and y >= 0 and
           x < m and y < n and grid[x][y] == 1)
        {
            
            grid[x][y] = 0;
            for(int i = 0; i < 4; i++)
                area += dfs(grid, x + dirs[i], y + dirs[i + 1]);
            
            return area;
        }
        
        else
            return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    maxArea = max(maxArea, dfs(grid, i, j));
        
        return maxArea;
    }
};