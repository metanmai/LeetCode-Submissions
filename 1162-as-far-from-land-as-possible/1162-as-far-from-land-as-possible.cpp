class Solution {
private:
    struct cell
    {
        int row, col;
    };
    
    vector<int> dirs = {0, 1, 0, -1, 0};
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), maxDist = 0;
        queue<cell> q;
        
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});
        
        while(!q.empty())
        {
            cell curr = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int x2 = curr.row + dirs[i], y2 = curr.col + dirs[i + 1];
                
                if(min(x2, y2) >= 0 and max(x2, y2) < n and
               grid[x2][y2] == 0)
                {
                    q.push({x2, y2});
                    maxDist = max(maxDist, grid[x2][y2] = grid[curr.row][curr.col] + 1);
                }
            }
        }
        
        return maxDist > 0 ? maxDist - 1 : -1;
    }
};