class Solution {
private:
    bool checkWords(string &s, set<string> &st, vector<int> &dp, int pos) {
        if (pos == s.length()) {
            return true;
        }
        if (dp[pos] != 0) {
            return dp[pos] == 1;
        }
        for (int i = pos + 1; i <= s.length(); i++) {
            if (st.find(s.substr(pos, i - pos)) != st.end() && checkWords(s, st, dp, i)) {
                dp[pos] = 1;
                return true;
            }
        }
        dp[pos] = -1;
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), 0);
        set<string> st = set(wordDict.begin(), wordDict.end());
        return checkWords(s, st, dp, 0);
    }
};
