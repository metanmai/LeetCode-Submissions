class Solution {
private:
    vector<vector<int>> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    double findProbability(vector<vector<vector<double>>> &dp, int row, int col, int k, int n)
    {
        // If the knight ever leaves the board, we return 0.
        if(!(min(row, col) >= 0 and max(row, col) < n))
            return 0;
        
        if(k == 0)
            return 1;
        
        if(dp[row][col][k] != -1)
            return dp[row][col][k];
        
        double prob = 0;
        
        for(auto dir : dirs)
            prob += findProbability(dp, row + dir[0], col + dir[1], k - 1, n);
        
        return dp[row][col][k] = prob / 8;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, -1)));
        return findProbability(dp, row, column, k, n);
    }
};