class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        for(int i = n - 1; i >= 0; i--)
            for(int canBuy = 0; canBuy <= 1; canBuy++)
                for(int transactions = 1; transactions <= 2; transactions++)
                    if(canBuy)
                        dp[i][canBuy][transactions] = max(dp[i + 1][0][transactions] - prices[i],
                                                          dp[i + 1][1][transactions]);

                    else
                        dp[i][canBuy][transactions] = max(dp[i + 1][1][transactions - 1] + prices[i],
                                                          dp[i + 1][0][transactions]);
        
        return dp[0][1][2];
    }
};