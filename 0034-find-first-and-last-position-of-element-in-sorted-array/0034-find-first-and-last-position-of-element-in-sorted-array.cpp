class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1, -1};
        
        vector<int> answer = {-1, -1};
        int n = nums.size();
        int low = 0, high = n - 1;
        
        // First Position.
        while(low < high)
        {
            int mid = midpoint(low, high);
            
            if(nums[mid] < target)
                low = mid + 1;
            
            else
                high = mid;
        }
        
        if(nums[high] == target)
            answer[0] = high;
        
        low = 0, high = n - 1;
        
        // Last Position.
        while(low < high)
        {
            int mid = midpoint(low + 1, high);
            
            if(nums[mid] <= target)
                low = mid;
            
            else
                high = mid - 1;
        }
        
        if(nums[low] == target)
            answer[1] = low;
        
        return answer;
    }
};