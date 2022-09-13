class Solution {
public:
    int paths(vector<vector<int>> grid, vector<vector<int>> &visited, int i, int j, int m, int n)
    {
        if(i >= m or j >= n or grid[i][j])
            return 0;
        
        if(i == m - 1 and j == n - 1) // This has to be 'and' and not 'or'.
            return 1;
        
        if(visited[i][j] != -1)
            return visited[i][j];
        
        return visited[i][j] = paths(grid, visited, i + 1, j, m, n) + paths(grid, visited, i, j + 1, m, n);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, -1));
        
        return paths(obstacleGrid, visited, 0, 0, m, n);
    }
};

