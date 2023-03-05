class Solution {
private:
    int findMaxJumps(vector<int> &arr, vector<int> &dp, int d, int start, int n)
    {
        if(dp[start] != 1)
            return dp[start];
        
        for(int k = 1; k <= d; k++)
        {
            if(start + k >= n or arr[start + k] >= arr[start])
                break;
            
            dp[start] = max(dp[start], 1 + findMaxJumps(arr, dp, d, start + k, n));
        }
        
        for(int k = 1; k <= d; k++)
        {
            if(start - k < 0 or arr[start - k] >= arr[start])
                break;
            
            dp[start] = max(dp[start], 1 + findMaxJumps(arr, dp, d, start - k, n));
        }
        
        return dp[start];
    }
    
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), maximumJump = 1;
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++)
            maximumJump = max(maximumJump, findMaxJumps(arr, dp, d, i, n));
        
        return maximumJump;
    }
};