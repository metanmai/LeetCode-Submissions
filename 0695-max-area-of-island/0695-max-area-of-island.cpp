// BFS Solution.

class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    int bfs(vector<vector<int>> &grid, int x, int y)
    {
        int area = 0;
        queue<vector<int>> q;
        q.push({x, y, 1});
        
        while(!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int r = cell[0], c = cell[1];
            
            if(r >= 0 and c >= 0 and
               r < m and c < n and grid[r][c] == 1)
            {
                area++;
                grid[r][c] = 0;
                
                for(int i = 0; i < 4; i++)
                    q.push({r + dirs[i], c + dirs[i + 1]});
                    
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                    maxArea = max(maxArea, bfs(grid, i, j));
        
        return maxArea;
    }
};