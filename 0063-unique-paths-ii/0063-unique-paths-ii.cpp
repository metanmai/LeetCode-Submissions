class Solution {
private:
    int paths(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, 
              int i, int j, int m, int n)
    {
        if(i >= m or j >= n or obstacleGrid[i][j] == 1)
            return 0;
        
        if(i == m - 1 and j == n - 1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = (paths(obstacleGrid, dp, i + 1, j, m, n) + 
                           paths(obstacleGrid, dp, i, j + 1, m, n));
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

        return paths(obstacleGrid, dp, 0, 0, m, n);
    }
};