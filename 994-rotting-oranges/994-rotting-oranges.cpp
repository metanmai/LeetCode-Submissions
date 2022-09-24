class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int freshCount = 0;
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    freshCount++;
                
                if(grid[i][j] == 2)
                { 
                    q.push({i, j, 0}); // The first 2 elements are for the index and the last element keeps track of the level, a.k.a time.
                    visited[i][j] = 2;
                }
            }
        
        int time, timeMax = 0, rotCount = 0;
        while(!q.empty())
        {
            auto front = q.front();
            int x = front[0], y = front[1], time = front[2];
            timeMax = max(time, timeMax);
            q.pop();
            
            for(auto i : directions)
            {
                int r = x + i[0], c = y + i[1];
                if(r < 0 or r >= m or 
                   c < 0 or c >= n or 
                   grid[r][c] != 1 or visited[r][c] == 2)
                    continue;

                q.push({r, c, time + 1});
                visited[r][c] = 2;
                rotCount++;
            }
        }
        return rotCount != freshCount ? -1 : timeMax;
    }
};