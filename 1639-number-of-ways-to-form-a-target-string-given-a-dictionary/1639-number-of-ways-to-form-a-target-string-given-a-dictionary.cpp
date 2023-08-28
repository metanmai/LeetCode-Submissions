class Solution {
private:
    using lolo = long long;
    int MOD = 1e9 + 7;
    
    lolo findNumberOfWays(vector<vector<int>> &dp, vector<string> &words, 
                         string &target, vector<vector<int>> &posFreqs, 
                         int i, int k, int n, int numWords, int wordLen)
    {
        if(i == n)
            return 1;
        
        if(k == wordLen)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        lolo ways = 0;
        
        ways = (ways + (posFreqs[k][target[i] - 'a'] * findNumberOfWays(dp, words, target, posFreqs, i + 1, k + 1, n, numWords, wordLen)) % MOD) % MOD;
        
        ways = (ways + findNumberOfWays(dp, words, target, posFreqs, i, k + 1, n, numWords, wordLen)) % MOD;
        
        
        return dp[i][k] = ways;
        
    }
    
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length(), numWords = words.size(), wordLen = words[0].length();
        vector<vector<int>> posFreqs(wordLen, vector<int> (26));
        vector<vector<int>> dp(n, vector<int> (wordLen, -1));
        
        for(int i = 0; i < numWords; i++)
            for(int k = 0; k < wordLen; k++)
                posFreqs[k][words[i][k] - 'a']++;
        
        return findNumberOfWays(dp, words, target, posFreqs, 0, 0, n, numWords, wordLen);
    }
};