class Solution {
    private int myBinarySearch(int[] nums, int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = (high + low) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid] < target)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return -1;
    }
    
    public int search(int[] nums, int target) {
        int low = 0, high = nums.length - 1, minIndex = -1;
        
        while(low < high && nums[low] > nums[high])
        {
            int mid = (high + low) / 2;
            
            if(nums[mid + 1] < nums[mid])
            {
                minIndex = mid + 1;
                break;
            }

            if(nums[mid] > nums[low])
                low = mid + 1;

            else
                high = mid;
        }
        
        
        if(minIndex == -1)
            minIndex = low;
        
        int search1 = myBinarySearch(nums, 0, minIndex - 1, target);
        int search2 = myBinarySearch(nums, minIndex, nums.length - 1, target);
        if(search1 != -1)
            return search1;

        if(search2 != -1)
            return search2;

        return -1;
    }
}