class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size(), shift = nums.front(), extra = 0;
        
        for(int i = 1; i < n; i++)
        {
            int currNum = i + shift + extra;
            
            if(nums[i] != currNum)
            {
                int diff = nums[i] - currNum;
                
                if(diff >= k)
                    return currNum + k - 1;
                
                k -= diff;
                extra += diff;
            }
        }
        
        return nums.back() + k;
    }
};