class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size(), low = 0, high = INT_MAX;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        auto canHeat = [&] (int radius) -> bool
        {
            int rightHouse = -1;
            
            for(int heater : heaters)
            {
                if(rightHouse < n - 1 and heater - radius > houses[rightHouse + 1])
                    return false;
                
                rightHouse = upper_bound(houses.begin(), houses.end(), heater + radius) - houses.begin() - 1;
            }
            
            return rightHouse >= n - 1;
        };
        
        while(low < high)
        {
            int mid = (high + low) / 2;
            
            if(canHeat(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high;
    }
};