class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        if(obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        
        vector<vector<long>> visited(m + 1, vector<long> (n + 1, 0));
        visited[m - 1][n - 1] = 1;
        
        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--)
                if(obstacleGrid[i][j])
                    visited[i][j] = 0;
                else
                    visited[i][j] += visited[i][j + 1] + visited[i + 1][j];
        
        return visited[0][0];
    }
};

