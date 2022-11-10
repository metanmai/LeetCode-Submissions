class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0;
        
        for(int i = 0; i < n; i++)
            if(currSum == totalSum - currSum - nums[i])
                return i;
            
            else
                currSum += nums[i];
        
        return -1;
    }
};