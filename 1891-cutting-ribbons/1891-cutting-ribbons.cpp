class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        long long low = 1, high = accumulate(ribbons.begin(), ribbons.end(), 0LL);
        
        if(k > high)
            return 0;
        
        auto canGetRibbons = [&] (int length) -> bool
        {
            long long ribs = 0;
            
            for(int ribbon : ribbons)
                ribs += ribbon / length;
            
            return ribs >= k;
        };
        
        while(low < high)
        {
            int mid = (low + high + 1) / 2;
            
            if(canGetRibbons(mid))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};