class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        
        for(int start = n - 1; start >= 0; start--)
        {
            int currSum = 0, currMax = 0;
            dp[start] = 0;
        
            for(int i = start; i < min(start + k, n); i++)
            {
                currMax = max(currMax, arr[i]);
                int prod = currMax * (i - start + 1) + dp[i + 1];

                dp[start] = max(dp[start], prod);
            }
        }
        
        return dp[0];
    }
};