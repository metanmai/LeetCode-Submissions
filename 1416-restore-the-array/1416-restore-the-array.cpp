/* 
Do not make use of substrings here as stoi will not work for large numbers. 
Instead, generate the number from the string and then perform comparison.
*/

class Solution {
private:
    using ll = long long;
    
    int MOD = 1e9 + 7;
    
    int findNumberOfArrays(vector<int> &dp, string &s, int k, int start, int n)
    {
        if(start == n)
            return 1;
        
        if(s[start] == '0')
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        ll ways = 0, num = 0;
        
        for(int i = start; i < n; i++)
        {
            num = num * 10 + (s[i] - '0');
            
            if(num > k)
                break;
            
            ways = (ways + findNumberOfArrays(dp, s, k, i + 1, n)) % MOD;
        }
        
        return dp[start] = ways;
    }
    
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        
        return findNumberOfArrays(dp, s, k, 0, n);
    }
};