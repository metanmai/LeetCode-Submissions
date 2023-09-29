class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while(low <= high)
        {
            int mid = midpoint(low, high);
            
            if(nums[mid] == target)
                return true;
            
            if (nums[low] == nums[mid])
            {
                low++; 
                continue;
            }
            
            bool pivotArray = nums[low] < nums[mid], targetArray = nums[low] <= target;
            
            if (pivotArray ^ targetArray)
            {
                if (pivotArray)
                    low = mid + 1;
                
                else
                    high = mid - 1;
            } 
            
            else
            {
                if (nums[mid] < target)
                    low = mid + 1;
                
                else
                    high = mid - 1;
            }
        }
        
        return false;
    }
};