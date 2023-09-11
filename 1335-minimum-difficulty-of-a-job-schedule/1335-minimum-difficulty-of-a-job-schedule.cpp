class Solution {
private:
    int findMinDifficulty(vector<vector<int>> &dp, vector<int> &jobDifficulty, int d, int start, int n)
    {
        if(d == 1)
            return *max_element(jobDifficulty.begin() + start, jobDifficulty.end());
        
        if(dp[start][d] != -1)
            return dp[start][d];
        
        int difficulty = INT_MAX, maxVal = jobDifficulty[start];
        
        for(int i = start; i < n - d + 1; i++)
        {
            maxVal = max(maxVal, jobDifficulty[i]);
            difficulty = min(difficulty, maxVal + findMinDifficulty(dp, jobDifficulty, d - 1, i + 1, n));
        }
        
        return dp[start][d] = difficulty;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size())
            return -1;
        
        int n = jobDifficulty.size();
        int maxEle = *max_element(jobDifficulty.begin(), jobDifficulty.end());
        vector<vector<int>> dp(n, vector<int> (d + 1, -1));
        
        return findMinDifficulty(dp, jobDifficulty, d, 0, n);
    }
};