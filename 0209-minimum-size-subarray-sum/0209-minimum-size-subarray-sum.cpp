class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX, i = 0, j = 0, currSum = 0;
        
        while(j < n)
        {
            currSum += nums[j];
            
            while(i <= j and currSum >= target)
            {
                minLen = min(minLen, j - i + 1);
                currSum -= nums[i++];
            }
            
            j++;
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};