class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int prevLen = 0, currLen = 0, maxLen = 0;
        nums.push_back(0);
        
        for(int i = 0; i < n + 1; i++)
        {
            if(nums[i] == 1)
                currLen++;
            
            else
            {
                maxLen = max(maxLen, currLen + prevLen);
                
                prevLen = currLen;
                currLen = 0;
            }
        }
            
        return maxLen == n ? n - 1 : maxLen;
    }
};