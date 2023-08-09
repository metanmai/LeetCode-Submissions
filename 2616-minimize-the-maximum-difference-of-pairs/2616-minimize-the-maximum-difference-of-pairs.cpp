class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        
        auto isValidPair = [&] (int diff) -> bool
        {
            int i = 1;
            int pairs = 0;
            
            while(i < n and pairs < p)
            {
                if(nums[i] - nums[i - 1] <= diff)
                    pairs++, i++;
                
                i++;
            }
            
            return pairs == p;
        };
        
        while(low < high)
        {
            int mid = (high + low) / 2;
            
            if(isValidPair(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};