class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while (low <= high) 
        {
            int mid = midpoint(low, high);
            
            if (nums[mid] == target)
                return mid;
            
            else if (nums[mid] >= nums[low]) // Left side is sorted.
            {
                if (target >= nums[low] and target < nums[mid]) 
                    high = mid - 1;
                
                else 
                    low = mid + 1;
            }
            
            else // Right side is sorted.
            {
                if (target <= nums[high] and target > nums[mid])
                    low = mid + 1;
                
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};