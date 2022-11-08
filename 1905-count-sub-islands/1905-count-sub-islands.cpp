class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    int m, n;
    
    void bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int &isSub)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while(!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second;
            
            if(x >= 0 and y >= 0 and
               x < m and y < n and grid2[x][y])
            {
                if(!grid1[x][y])
                    isSub = 0;
                
                grid2[x][y] = 0;
                
                for(int i = 0; i < 4; i++)
                    q.push({x + dirs[i], y + dirs[i + 1]});
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size(), n = grid2[0].size();
        int subIslands = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid2[i][j])
                {
                    int isSub = 1;
                    bfs(grid1, grid2, i, j, isSub);
                    subIslands += isSub;
                }
        
        return subIslands;
    }
};