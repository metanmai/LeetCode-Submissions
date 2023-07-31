class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size(), shift = nums.front(), extra = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != shift + i + extra)
            {
                int diff = nums[i] - (shift + i + extra);
                
                if(diff >= k)
                    return shift + i + extra + k - 1;
                
                k -= diff;
                extra += nums[i] - (shift + i + extra);
            }
        }
        
        return nums.back() + k;
    }
};