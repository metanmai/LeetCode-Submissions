class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), robCurr = 0, robNext = 0, robNextNext = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            robCurr = max(robNext, nums[i] + robNextNext);
            robNextNext = robNext;
            robNext = robCurr;
        }
        
        return robCurr;
    }
};