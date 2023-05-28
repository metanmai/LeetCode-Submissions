class Solution {
private:
    int findMaxScore(vector<int> &stoneValue, vector<vector<int>> &dp, 
                     vector<int> &prefix, int start, int end)
    {
        if(start == end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int maxScore = 0;
        
        for(int i = start; i < end; i++)
        {
            int left = prefix[i + 1] - prefix[start];
            int right = prefix[end + 1] - prefix[i + 1];
            
            if(left < right)
                maxScore = max(maxScore, 
                               left + findMaxScore(stoneValue, dp, prefix, start, i));
            
            else if(left > right)
                maxScore = max(maxScore, 
                               right + findMaxScore(stoneValue, dp, prefix, i + 1, end));
            
            else
                maxScore = max(maxScore,
                               max(left + findMaxScore(stoneValue, dp, prefix, start, i),
                                   right + findMaxScore(stoneValue, dp, prefix, i + 1, end)));
        }
        
        return dp[start][end] = maxScore;
    }
    
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix = {0};
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int val : stoneValue)
            prefix.push_back(prefix.back() + val);
        
        return findMaxScore(stoneValue, dp, prefix, 0, n - 1);
    }
};