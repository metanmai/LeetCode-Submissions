class Solution {
private:
    bool checkWords(string &s, set<string> &words, vector<int> &dp, int start, int n) {
        if (start == n)
            return true;
        
        if (dp[start] != -1)
            return dp[start];
        
        for (int i = start; i < n; i++) 
            if (words.find(s.substr(start, i - start + 1)) != words.end() and 
                checkWords(s, words, dp, i + 1, n))
                return dp[start] = 1;
    
        return dp[start] = 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n, -1);
        set<string> words = set(wordDict.begin(), wordDict.end());
        
        return checkWords(s, words, dp, 0, n);
    }
};
