// BFS Solution.

class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    void bfs(vector<vector<int>> &grid, int x, int y)
    {
        queue<vector<int>> q;
        q.push({x, y});
        
        while(!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int r = cell[0], c = cell[1];
            
            if(r >= 0 and c >= 0 and
               r < m and c < n and grid[r][c] == 0)
            {
                grid[r][c] = 1;
                for(int i = 0; i < 4; i++)
                    q.push({r + dirs[i], c + dirs[i + 1]});
            }
            
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < m; i++)
        {
            if(grid[i][0] == 0)
                bfs(grid, i, 0);
            
            if(grid[i][n - 1] == 0)
                bfs(grid, i, n - 1);
        }
        
        for(int j = 0; j < n; j++)
        {
            if(grid[0][j] == 0)
                bfs(grid, 0, j);
            
            if(grid[m - 1][j] == 0)
                bfs(grid, m - 1, j);
        }
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0)
                {
                    bfs(grid, i, j);
                    islands++;
                }
        return islands;
    }
};