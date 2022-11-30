class Solution {
private:
    struct cell
    {
        int x, y;
    };
    
    int n, dirs[5] = {0, 1, 0, -1, 0};
    
    void color(vector<vector<int>> &grid, int i, int j, queue<cell> &q)
    {
        if(min(i, j) >= 0 and max(i, j) < n and grid[i][j] == 1)
        {
            grid[i][j] = 2;
            q.push({i, j});
            
            for(int k = 0; k < 4; k++)
                color(grid, i + dirs[k], j + dirs[k + 1], q);
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        int colored = 0;
        queue<cell> q;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1 and !colored)
                    color(grid, i, j, q), colored = 1;
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nx = curr.x + dirs[i], ny = curr.y + dirs[i + 1];
                if(min(nx, ny) >= 0 and max(nx, ny) < n)
                {
                    if(grid[nx][ny] == 0)
                    {
                        grid[nx][ny] = 1 + grid[curr.x][curr.y];
                        q.push({nx, ny});
                    }
                    
                    if(grid[nx][ny] == 1)
                        return grid[curr.x][curr.y] - 2;
                }
            }
        }
        
        return 0;
    }
};