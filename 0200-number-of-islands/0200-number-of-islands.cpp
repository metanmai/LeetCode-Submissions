class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if(x >= grid.size() or y >= grid[0].size() or x < 0 or y < 0 or grid[x][y] != '1')
            return;
        
        grid[x][y] = '2';
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
        
        return count;
    }
};