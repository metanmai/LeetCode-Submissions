class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        
        auto isValidDivisor = [&] (int div) -> bool
        {
            int totalSum = 0;
            
            for(int num : nums)
                totalSum += ceil((float) num / div);
            
            return totalSum <= threshold;
        };
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(isValidDivisor(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};