class Solution {
private:
    int findBestScore(vector<vector<int>> &dp, vector<vector<int>> &players, 
                      int prev, int i, int n)
    {
        if(i == n)
            return 0;
        
        if(dp[prev + 1][i] != -1)
            return dp[prev + 1][i];
        
        int take = 0, notTake = 0;
        
        if(prev == -1 or players[i][1] >= players[prev][1])
            take = players[i][1] + findBestScore(dp, players, i, i + 1, n);
        
        notTake = findBestScore(dp, players, prev, i + 1, n);
        
        return dp[prev + 1][i] = max(take, notTake);
    }
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> players(n), dp(n, vector<int> (n, -1));
        
        for(int i = 0; i < n; i++)
            players[i] = {ages[i], scores[i]};
        
        sort(players.begin(), players.end());
        
        return findBestScore(dp, players, -1, 0, n);
    }
    
};