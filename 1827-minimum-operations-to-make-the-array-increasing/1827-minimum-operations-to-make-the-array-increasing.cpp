class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0;
        
        for(int i = 1; i < n; i++)
            if(nums[i] <= nums[i - 1])
            {
                int diff = nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
                ops += diff;
            }
        
        return ops;
    }
};