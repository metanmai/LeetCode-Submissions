class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7 + 1;
        
        auto canReachOnTime = [&] (int speed) -> bool
        {
            double time = 0;
            
            for(int i = 0; i < dist.size() - 1; i++)
                time += ceil((double) dist[i] / speed);
            
            time += (double) dist.back() / speed;
            
            return time <= hour;
        };
        
        while(low < high)
        {
            int mid = (high + low) / 2;
            
            if(canReachOnTime(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return high == 1e7 + 1 ? -1 : high;
    }
};