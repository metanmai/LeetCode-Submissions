class Solution {
private:
    int maxLines(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp,
                 int i, int j, int n1, int n2)
    {
        if(i == n1 or j == n2)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i] == nums2[j])
            return dp[i][j] = 1 + maxLines(nums1, nums2, dp, i + 1, j + 1, n1, n2);
        
        return dp[i][j] = max(maxLines(nums1, nums2, dp, i + 1, j, n1, n2),
                              maxLines(nums1, nums2, dp, i, j + 1, n1, n2));
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return maxLines(nums1, nums2, dp, 0, 0, nums1.size(), nums2.size());
    }
};