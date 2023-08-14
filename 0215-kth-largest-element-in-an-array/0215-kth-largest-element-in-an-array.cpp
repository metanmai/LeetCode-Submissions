class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), low = 0, high = n - 1;
        
        while(low < high)
        {
            int pivot = low;

            for(int i = low; i < high; i++)
                if(nums[i] <= nums[high])
                    swap(nums[pivot++], nums[i]);
            
            swap(nums[pivot], nums[high]);

            if(pivot > n - k)
                high = pivot - 1;
            
            else if(pivot < n - k)
                low = pivot + 1;
            
            else
                return nums[pivot];
        }

        return nums[low];
    }
};