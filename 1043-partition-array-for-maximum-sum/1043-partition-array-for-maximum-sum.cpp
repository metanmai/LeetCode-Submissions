class Solution {
private:
    int findMaxPartSum(vector<int> &dp, vector<int> &arr, int k, int start, int n)
    {
        if(dp[start] != -1)
            return dp[start];
        
        int maxVal = 0, currSum = 0, currMax = 0;
        
        for(int i = start; i < min(start + k, n); i++)
        {
            currMax = max(currMax, arr[i]);
            
            int prod = currMax * (i - start + 1) + findMaxPartSum(dp, arr, k, i + 1, n);
            
            maxVal = max(maxVal, prod);
        }
        
        return dp[start] = maxVal;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        
        return findMaxPartSum(dp, arr, k, 0, n);
    }
};