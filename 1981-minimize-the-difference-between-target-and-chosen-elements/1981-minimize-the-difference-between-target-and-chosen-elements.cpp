class Solution {
private:
    int findMinDifference(vector<vector<int>> &dp, vector<vector<int>> &mat, int target, 
                          int i, int m, int n, int maxSum)
    {
        if(i == m)
            return abs(target);
        
        if(dp[maxSum + target][i] != -1)
            return dp[maxSum + target][i];
        
        int minDiff = INT_MAX;
        
        for(int j = 0; j < n; j++)
            minDiff = min(minDiff, findMinDifference(dp, mat, target - mat[i][j], i + 1, m, n, maxSum));
        
        return dp[maxSum + target][i] = minDiff;
    }
    
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int maxSum = 0;
        
        for(auto &row : mat)
            maxSum += *max_element(row.begin(), row.end());
        
        vector<vector<int>> dp(maxSum + target + 1, vector<int> (m, -1));
        
        return findMinDifference(dp, mat, target, 0, m, n, maxSum);
    }
};