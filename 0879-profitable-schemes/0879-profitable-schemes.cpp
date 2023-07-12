class Solution {
private:
    int MOD = 1e9 + 7;
    
    int findProfitableSchemes(vector<vector<vector<int>>> &dp, 
                              vector<int> &group, vector<int> &profit, int total,
                              int n, int minProfit, int i, int len)
    {
        if(i == len)
            return minProfit <= 0;
        
        if(dp[n][minProfit + total][i] != -1)
            return dp[n][minProfit + total][i];
        
        int schemes = 0;
        
        if(n - group[i] >= 0)
            schemes += findProfitableSchemes(dp, group, profit, total, n - group[i], 
                                             minProfit - profit[i], i + 1, len);
        
        schemes += findProfitableSchemes(dp, group, profit, total, n, minProfit, i + 1, len);
        
        return dp[n][minProfit + total][i] = schemes % MOD;
    }
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size();
        int total = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (minProfit + total + 1, 
                                                                  vector<int> (len + 1, -1)));
        
        return findProfitableSchemes(dp, group, profit, total, n, minProfit, 0, len);
    }
};