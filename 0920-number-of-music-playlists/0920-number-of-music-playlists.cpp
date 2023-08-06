class Solution {
private:
    int MOD = 1e9 + 7;
    
    int getNumPlaylists(vector<vector<int>> &dp, int usedSongs, int goal, int k, int n)
    {
        if(goal == 0)
            return usedSongs == n;
        
        if(dp[usedSongs][goal] != -1)
            return dp[usedSongs][goal];
        
        int useNewSong = 0, notUseNewSong = 0;
        
        if(usedSongs < n)
            useNewSong = ((long long) (n - usedSongs) * getNumPlaylists(dp, usedSongs + 1, goal - 1, k, n)) % MOD;
        
        if(usedSongs > k)
            notUseNewSong = ((long long) (usedSongs - k) * getNumPlaylists(dp, usedSongs, goal - 1, k, n)) % MOD;
        
        return dp[usedSongs][goal] = (useNewSong + notUseNewSong) % MOD;
    }
    
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int> (goal + 1, -1));
        
        return getNumPlaylists(dp, 0, goal, k, n);
    }
};