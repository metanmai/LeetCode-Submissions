class Solution {
private:
    int findCombinations(vector<vector<int>> &dp, vector<int> &coins, 
                         int amount, int i, int n)
    {
        if(i == n or amount < 0)
            return 0;
        
        if(amount == 0)
            return 1;
        
        if(dp[amount][i] != -1)
            return dp[amount][i];
        
        int stay = findCombinations(dp, coins, amount - coins[i], i, n);
        int next = findCombinations(dp, coins, amount, i + 1, n);
        
        return dp[amount][i] = stay + next;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int> (n, -1));
        return findCombinations(dp, coins, amount, 0, n);
    }
};