/* 
Top-Down DP Solution.
Time Complexity: O(n^2)
Space Complexity; O(n^2)

This problem is similar to House Robber 2. The additional parameter here is n, as we cannot take
More than n slices.
*/

class Solution {
public:
   int getMaxSlices(int ind, int end, vector<int>&slices, int n, vector<vector<int>> &dp)
   {
        if(n == 0 or ind > end)
            return 0;
       
        if(dp[ind][n] != -1)
            return dp[ind][n];
       
        int take = slices[ind] + getMaxSlices(ind + 2, end, slices, n - 1, dp);
        int notTake = 0 + getMaxSlices(ind + 1, end, slices, n, dp);
       
        return dp[ind][n] = max(take, notTake);
   }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int> (n, -1)), dp2(n, vector<int> (n, -1));
        
        int r1 = getMaxSlices(0, n - 2, slices, n / 3, dp1);
        int r2 = getMaxSlices(1, n - 1, slices, n / 3, dp2);
        
        return max(r1, r2);
    }
};