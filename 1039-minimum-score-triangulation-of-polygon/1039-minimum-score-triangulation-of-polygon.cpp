class Solution {
private:
    int solve(vector<vector<int>> &dp, vector<int> &values, int i, int j)
    {
        if(i == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for(int k = i; k < j; k++)
        {
            int tempAns = (
                solve(dp, values, i, k) + solve(dp, values, k + 1, j) + 
                values[i - 1] * values[k] * values[j]
            );
            mini = min(mini, tempAns);
        }  

        return dp[i][j] = mini;      
    }
    
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solve(dp, values, 1, n - 1);
    }
};