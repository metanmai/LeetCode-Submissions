class Solution {
    public int jump(int[] nums) {
        int n = nums.length, dp[] = new int[n];
        
        for(int i = 0; i < n; i++)
            dp[i] = Integer.MAX_VALUE;
        
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; i--)
            for(int k = 1; k <= nums[i]; k++)
            {
                if(i + k >= n - 1)
                    dp[i] = 1;
                
                else if(dp[i + k] == Integer.MAX_VALUE)
                    continue;
                
                else
                    dp[i] = Math.min(dp[i], dp[i + k] + 1);
            }
        
        return dp[0];
    }
}