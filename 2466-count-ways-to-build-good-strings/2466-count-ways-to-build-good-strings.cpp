class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD = 1e9 + 7, answer = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= high; i++)
        {
            if(i - zero >= 0)
                dp[i] += dp[i - zero] % MOD;
            
            if(i - one >= 0)
                dp[i] += dp[i - one] % MOD;
            
        }
        
        for(int i = low; i <= high; i++)
        {
            answer += dp[i] % MOD;
            answer %= MOD;
        }
        
        return answer;
    }
};