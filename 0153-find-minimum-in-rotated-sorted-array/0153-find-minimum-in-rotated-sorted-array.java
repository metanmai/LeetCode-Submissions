class Solution {
    public int findMin(int[] nums) {
        int low = 0, high = nums.length - 1;
        
        while(low < high && nums[low] > nums[high])
        {
            int mid = (high + low) / 2;
            
            if(nums[mid + 1] < nums[mid])
                return nums[mid + 1];

            if(nums[mid] > nums[low])
                low = mid + 1;

            else
                high = mid;
        }
        
        return nums[low];
    }
}