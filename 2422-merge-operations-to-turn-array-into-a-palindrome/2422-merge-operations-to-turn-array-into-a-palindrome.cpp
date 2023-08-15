class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1;
        int operations = 0;
        
        while(i < j)
        {
            if(nums[i] == nums[j])
            {
                i++, j--;
                continue;
            }
            
            if(nums[i] < nums[j])
            {
                nums[j] -= nums[i];
                i++;
            }
            
            else
            {
                nums[i] -= nums[j];
                j--;
            }
            
            operations++;
        }
        
        return operations;
    }
};