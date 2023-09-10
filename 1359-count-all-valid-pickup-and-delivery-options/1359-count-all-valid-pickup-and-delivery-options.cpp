// Brother man this is somewhat like parentheses. DP Solution
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
private:
    int MOD = 1e9 + 7;
    using lolo = long long;
    
    lolo totalWays(vector<vector<int>> &dp, int unpicked, int undelivered) {
        if (unpicked == 0 and undelivered == 0)
            return 1;
        
        if (unpicked < 0 or undelivered < 0 or undelivered < unpicked)
            return 0;
        
        if (dp[unpicked][undelivered] != -1)
            return dp[unpicked][undelivered];
        
        lolo ways = 0;
        
        ways = (ways + (unpicked * totalWays(dp, unpicked - 1, undelivered))) % MOD;
        ways = (ways + ((undelivered - unpicked) * totalWays(dp, unpicked, undelivered - 1))) % MOD;
        
        return dp[unpicked][undelivered] = ways;
    }
    
public:
    int countOrders(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return totalWays(dp, n, n);
    }
};