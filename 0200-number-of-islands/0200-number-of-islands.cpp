// BFS Solution.

class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int r = front.first + dirs[i], c = front.second + dirs[i + 1];
                if(r >= 0 and c >= 0 and
                   r < m and c < n and 
                   grid[r][c] == '1')
                {
                    grid[r][c] = '2';
                    q.push({r, c});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    islands++;
                }
        
        return islands;
    }
};