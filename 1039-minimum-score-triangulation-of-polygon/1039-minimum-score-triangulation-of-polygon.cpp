#define MAXI numeric_limits<int>::max()
/*
Top-Down Partition Solution.
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

class Solution {
private:
    int findMinScore(vector<vector<int>> &dp, vector<int> &values, int i, int j)
    {
        if(j - i == 1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int minScore = MAXI;
        
        for(int k = i + 1; k < j; k++)
        {
            int currScore = values[i] * values[k] * values[j];
            int leftScore = findMinScore(dp, values, i, k);
            int rightScore = findMinScore(dp, values, k, j);
            
            minScore = min(minScore, currScore + leftScore + rightScore);
        }
        
        return dp[i][j] = minScore;
    }
    
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return findMinScore(dp, values, 0, values.size() - 1);
    }
};