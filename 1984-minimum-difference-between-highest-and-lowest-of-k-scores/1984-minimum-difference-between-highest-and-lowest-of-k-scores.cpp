class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff = nums.back() - nums[0];
        
        for(int i = 0, j = k - 1; j < nums.size(); i++, j++)
            minDiff = min(minDiff, nums[j] - nums[i]);
        
        return minDiff;
    }
};