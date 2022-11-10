class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int currSum = 0, mini = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            mini = min(mini, currSum);
        }
        
        return mini == 0 ? 1 : abs(mini) + 1;
    }
};