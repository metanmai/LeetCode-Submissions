class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    
    void dfs(int x, int y, int m, int n, vector<vector<int>> &grid, vector<pair<int, int>> &island)
    {
        if(x < 0 or y < 0 or x >= m or y >= n or !grid[x][y])
            return;
        
        grid[x][y] = 0;
        island.push_back({x, y});
        for(int i = 0; i < 4; i++)
            dfs(x + dir[i], y + dir[i + 1], m, n, grid, island);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> islands;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                vector<pair<int, int>> island;
                
                if(grid[i][j])
                   dfs(i, j, m, n, grid, island);
                
                for(auto &cell : island)
                {
                    cell.first -= i;
                    cell.second -= j;
                }
                
                if(island.size())
                    islands.insert(island);
            }
        
        return islands.size();
    }
};