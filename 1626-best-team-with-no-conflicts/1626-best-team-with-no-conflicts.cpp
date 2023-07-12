class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> players(n), dp(n + 1, vector<int> (n + 1));
        
        for(int i = 0; i < n; i++)
            players[i] = {ages[i], scores[i]};
        
        sort(players.begin(), players.end());
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int prev = n - 1; prev >= -1; prev--)
            {
                int take = 0, notTake = 0;
        
                if(prev == -1 or players[i][1] >= players[prev][1])
                    take = players[i][1] + dp[i + 1][i + 1];

                notTake = dp[prev + 1][i + 1];
                
                dp[prev + 1][i] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }
    
};