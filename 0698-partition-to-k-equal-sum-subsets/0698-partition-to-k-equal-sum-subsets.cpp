class Solution {
private:
    bool canPartition(vector<int> &nums, int k, int start, int currSum, int targetSum, int mask, int bits, int n)
    {
        if(mask == bits and k == 1)
            return currSum == targetSum;
        
        if(k == 0)
            return false;
        
        if(currSum == targetSum)
            return canPartition(nums, k - 1, 0, 0, targetSum, mask, bits, n);
        
        for(int i = start; i < n; i++)
            if(currSum < targetSum and (mask & (1 << i)) == 0 and 
               canPartition(nums, k, i + 1, currSum + nums[i], 
                            targetSum, mask | (1 << i), bits, n))
               return true;
               
        return false;
        
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), bits = pow(2, n) - 1;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        
        if(totalSum % k != 0)
            return false;
        
        int targetSum = totalSum / k;
        
        return canPartition(nums, k, 0, 0, targetSum, 0, bits, n);
    }
};