class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        int mini = *min_element(arr.begin(), arr.end());
        int shift = 0, maxLen = 0;
        
        if(mini < 0)
            shift += -mini;
        
        if(diff < 0)
            shift += - diff;
        
        vector<int> dp(maxi + shift + max(0, diff) + 1);
        
        for(int i = n - 1; i >= 0; i--)
            maxLen = max(maxLen, dp[arr[i] + shift] = max(dp[arr[i] + shift], 
                                                          1 + dp[arr[i] + diff + shift]));
        
        return maxLen;
    }
};