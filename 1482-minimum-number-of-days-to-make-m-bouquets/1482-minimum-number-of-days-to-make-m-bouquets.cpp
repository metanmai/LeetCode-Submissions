class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        if((long long) m * k > n)
            return -1;
        
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        
        auto canMakeBouquet = [&] (int days) -> bool
        {
            int bouquets = 0, counter = 0;
            
            for(int i = 0; i < n; i++)
            {
                if(bloomDay[i] > days)
                {
                    counter = 0;
                    continue;
                }
                
                counter++;
                
                if(counter % k == 0)
                    bouquets++;
            }
            
            return bouquets >= m;
        };
        
        while(low < high)
        {
            int mid = (low + high) / 2;
            
            if(canMakeBouquet(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};