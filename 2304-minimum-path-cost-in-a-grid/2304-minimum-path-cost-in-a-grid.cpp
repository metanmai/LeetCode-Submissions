class Solution {
private:
    int findMinPathCost(vector<vector<int>> &dp, vector<vector<int>> &grid, vector<vector<int>> &moveCost, int r, int c, int m, int n)
    {
        if(r == m - 1)
            return grid[r][c];
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        int cost = INT_MAX;
        
        for(int j = 0; j < n; j++)
            cost = min(cost, (grid[r][c] + moveCost[grid[r][c]][j] + 
                              findMinPathCost(dp, grid, moveCost, r + 1, j, m, n)));
        
        return dp[r][c] = cost;
    }
    
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size(), minCost = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        for(int j = 0; j < n; j++)
            minCost = min(minCost, findMinPathCost(dp, grid, moveCost, 0, j, m, n));
        
        return minCost;
    }
};