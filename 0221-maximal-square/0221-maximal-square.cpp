class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxSquare = 0;
        vector<vector<int>> dp(m, vector<int> (n));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = matrix[i][j] - '0';
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(i != m - 1 and j != n - 1 and
                   dp[i][j] != 0 and
                   dp[i][j + 1] != 0 and
                   dp[i + 1][j] != 0 and
                   dp[i + 1][j + 1] != 0)
                    dp[i][j] = min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }
        
        return maxSquare * maxSquare;
    }
};