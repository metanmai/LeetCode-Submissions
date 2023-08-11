class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxMoves = 0;
        vector<vector<int>> dp(m, vector<int> (n));
        
        for(int j = n - 2; j >= 0; j--)
        {
            for(int i = m - 1; i >= 0; i--)
            {   
                int path1 = i > 0 and grid[i - 1][j + 1] > grid[i][j] ? dp[i - 1][j + 1] : -1;
                int path2 = grid[i][j + 1] > grid[i][j] ? dp[i][j + 1] : -1;
                int path3 = i < m - 1 and grid[i + 1][j + 1] > grid[i][j] ? dp[i + 1][j + 1] : - 1;
                
                if(path1 + path2 + path3 == -3)
                    continue;
                
                else
                    dp[i][j] = 1 + max(path1, max(path2, path3));
            }
        }
        
        for(int i = 0; i < m; i++)
            maxMoves = max(maxMoves, dp[i][0]);
        
        return maxMoves;
    }
};