class Solution {
private:
    int maxScore(vector<int> &piles, vector<vector<vector<int>>> &dp,
                 vector<int> &prefix, int pos, int m, int n, bool alice)
    {
        if(pos == n)
            return 0;
        
        if(dp[pos][m][alice] != -1)
            return dp[pos][m][alice];
        
        int score = alice ? 0 : INT_MAX;
        
        for(int i = pos; i < min(n, pos + 2 * m); i++)
        {
            if(alice)
                score = max(score, 
                            (prefix[i + 1] - prefix[pos] +
                             maxScore(piles, dp, prefix, i + 1, max(m, i + 1 - pos), n, !alice)));
            
            else
                score = min(score, 
                            maxScore(piles, dp, prefix, i + 1, max(m, i + 1 - pos), n, !alice));
        }
        
        return dp[pos][m][alice] = score;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2 * n, vector<int> (2, -1)));
        vector<int> prefix = {0};
        
        for(int pile : piles)
            prefix.push_back(prefix.back() + pile);
        
        return maxScore(piles, dp, prefix, 0, 1, n, true);
    }
};