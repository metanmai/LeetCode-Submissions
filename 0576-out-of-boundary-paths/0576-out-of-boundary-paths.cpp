class Solution {
private:
    int MOD = 1e9 + 7;
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    int getTotalPaths(vector<vector<vector<int>>> &dp, int row, int col, int maxMove, int m, int n)
    {
        if(min(row, col) < 0 or row >= m or col >= n)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        if(dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];
        
        int paths = 0;
        
        for(int i = 0; i < 4; i++)
            paths = (paths + getTotalPaths(dp, row + dirs[i], col + dirs[i + 1], maxMove - 1, m, n)) % MOD;
        
        return dp[row][col][maxMove] = paths;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        return getTotalPaths(dp, startRow, startColumn, maxMove, m, n);
    }
};