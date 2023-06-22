class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] > ((mid + 1) == n ? INT_MIN : nums[mid + 1]))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};