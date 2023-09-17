// DP Solution.
/*
You do not require a visited matrix, we only need to account for duplicate entries
because for a given row, if both robot1 and robot2 reach the same cell, but
the cell gets counted only once, it will never be the max value anyway.
*/

class Solution {
private:
    int findMaxPickup(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, 
                      int row, int col1, int col2, int m, int n)
    {
        if(row == m or col1 >= n or col2 >= n or min(col1, col2) < 0)
            return 0;
        
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        int pickup = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);
        int nextPickup = 0, nextRow = row + 1;
        
        for(int nextCol1 = col1 - 1; nextCol1 <= col1 + 1; nextCol1++)
            for(int nextCol2 = col2 - 1; nextCol2 <= col2 + 1; nextCol2++)
                nextPickup = max(nextPickup, 
                                 findMaxPickup(grid, dp, nextRow, nextCol1, nextCol2, m, n));
        
        return dp[row][col1][col2] = pickup + nextPickup;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return findMaxPickup(grid, dp, 0, 0, n - 1, m, n);
    }
};