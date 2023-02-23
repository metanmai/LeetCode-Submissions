class Solution {
        public int numberOfWays(int n) {
            int MOD = (int) 1e9 + 7;
            long[] dp = new long[n / 2 + 1];
            dp[0] = 1;
            
            for (int k = 1; k <= n / 2; ++k)
                for (int i = 0; i < k; ++i)
                    dp[k] = (dp[k] + dp[i] * dp[k - 1 - i]) % MOD;
            
            return (int)dp[n / 2];
    }
}