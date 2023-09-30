#define MAXI numeric_limits<int>::max()
/*
Bottom-Up Partition Solution.
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, MAXI));
        
        for(int j = 1; j < n; j++)
        {
            dp[j - 1][j] = 0;
            
            for(int i = j - 1; i >= 0; i--)
            {
                for(int k = i + 1; k < j; k++)
                {
                    int currScore = values[i] * values[k] * values[j];
                    int leftScore = dp[i][k];
                    int rightScore = dp[k][j];

                    dp[i][j] = min(dp[i][j], currScore + leftScore + rightScore);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};