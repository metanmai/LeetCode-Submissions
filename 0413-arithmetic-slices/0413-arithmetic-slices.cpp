class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), diff, len, answer = 0;
        int i = 0, j = 1;
        
        while(j < nums.size())
        {
            if(j - i < 2)
            {
                j++;
                continue;
            }
            
            diff = nums[i + 1] - nums[i];
            
            if(nums[j] - nums[j - 1] == diff)
                j++;
            
            else
            {
                len = j - i;
                answer += (len - 2) * (len - 1) / 2;
                i = j - 1;
            }
        }
        
        len = j - i;
        
        return answer + (len - 2) * (len - 1) / 2;
    }
};