class Solution {
private:
    int findScore(vector<int> &stoneValue, vector<vector<int>> &dp, 
                  vector<int> &prefix, int pos, bool alice, int n)
    {
        if(pos == n)
            return 0;
        
        if(dp[pos][alice] != -1)
            return dp[pos][alice];
        
        int score = alice ? INT_MIN : INT_MAX;
        
        for(int i = pos; i < min(n, pos + 3); i++)
        {
            if(alice)
                score = max(score, 
                            (prefix[i + 1] - prefix[pos] + 
                             findScore(stoneValue, dp, prefix, i + 1, !alice, n)));
            
            else
                score = min(score, 
                            findScore(stoneValue, dp, prefix, i + 1, !alice, n));
        }
        
        return dp[pos][alice] = score;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(), totalVal = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<int> prefix = {0};
        vector<vector<int>> dp(n, vector<int> (2, -1));
        
        for(int val : stoneValue)
            prefix.push_back(prefix.back() + val);
        
        int aliceScore = findScore(stoneValue, dp, prefix, 0, true, n);
        int bobScore = totalVal - aliceScore;
        
        if(aliceScore > bobScore)
            return "Alice";
        
        else if(aliceScore < bobScore)
            return "Bob";
        
        else
            return "Tie";
    }
};