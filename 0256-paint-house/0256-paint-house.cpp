class Solution {
private:
    int findMinCost(vector<vector<int>> &dp, vector<vector<int>> &costs, 
                    int prevColor, int i, int n)
    {
        if(i == n)
            return 0;
        
        if(dp[prevColor + 1][i] != -1)
            return dp[prevColor + 1][i];
        
        vector<int> colors(3, INT_MAX);
        
        for(int k = 0; k < 3; k++)
        {
            if(k == prevColor)
                continue;
            
            colors[k] = costs[i][k] + findMinCost(dp, costs, k, i + 1, n);
        }
        
        return dp[prevColor + 1][i] = *min_element(colors.begin(), colors.end());
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(4, vector<int> (n + 1, -1));
    
        return findMinCost(dp, costs, -1, 0, n);
    }
};