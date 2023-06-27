class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end()), high = *max_element(nums.begin(), nums.end());
        
        auto canRob = [&] (int cap) -> bool
        {
            int i = 0, robbed = 0;
            
            while(i < n)
            {
                if(nums[i] > cap)
                    i++;
                
                else
                {
                    robbed++;
                    i += 2;
                }
            }
            
            return robbed >= k;
        };
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(canRob(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};