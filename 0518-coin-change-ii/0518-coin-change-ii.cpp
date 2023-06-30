class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int> (n + 1));
        
        for(int j = 0; j <= n; j++)
            dp[0][j] = 1;
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= amount; j++)
            {
                int stay = j - coins[i] >= 0 ? dp[j - coins[i]][i] : 0;
                int next = dp[j][i + 1];

                dp[j][i] = stay + next;
            }
        }
        
        return dp[amount][0];
    }
};