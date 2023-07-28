class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), maxSum = -1;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            int nextNum = k - (nums[i]);
            int nextNumPos = lower_bound(nums.begin() + i + 1, nums.end(), nextNum) - nums.begin() - 1;
            if(nextNumPos > i)
                maxSum = max(maxSum, nums[nextNumPos] + nums[i]);
        }
        
        return maxSum;
    }
};