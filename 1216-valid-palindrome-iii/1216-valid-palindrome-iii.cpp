/* 
Here, we don't need to send k as a parameter. Instead, find the minimum cost required
to create a palindrome and then check if it is lesser than or equal to k.
*/

class Solution {
private:
    int minCostPalindrome(vector<vector<int>> &dp, string &s, int i, int j, int n)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        while(i < j)
        {
            if(s[i] != s[j])
                return (dp[i][j] = 1 + min(
                minCostPalindrome(dp, s, i + 1, j, n),
                minCostPalindrome(dp, s, i, j - 1, n)
                ));
            
            else
                i++, j--;
        }
        
        return 0;
    }
    
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return minCostPalindrome(dp, s, 0, n - 1, n) <= k;
    }
};