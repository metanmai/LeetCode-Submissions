class Solution {
private:
    bool isValidPartition(vector<int> &dp, vector<int> &nums, int i, int n)
    {
        if(i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool answer = false;
        
        if(i < n - 1 and nums[i] == nums[i + 1])
            answer = isValidPartition(dp, nums, i + 2, n);
        
        if(i < n - 2 and 
           ((nums[i] == nums[i + 1] - 1 and nums[i] == nums[i + 2] - 2) or
           (nums[i] == nums[i + 1] and nums[i] == nums[i + 2])))
            answer |= isValidPartition(dp, nums, i + 3, n);
        
        return dp[i] = answer;
    }
    
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return isValidPartition(dp, nums, 0, n);
    }
};