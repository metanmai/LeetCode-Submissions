class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        int MOD = 1e9 + 7;
        int answer = 0;
        vector<int> dp(maxLength + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= maxLength; i++)
        {
            if(i >= oneGroup)
                dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
            
            if(i >= zeroGroup)
                dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
            
            if(i >= minLength)
                answer = (answer + dp[i]) % MOD;
        }
        
        return answer;
    }
};