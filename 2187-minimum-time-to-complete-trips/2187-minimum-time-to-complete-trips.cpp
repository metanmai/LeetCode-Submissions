#define ll long long

class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        
        function<bool(ll)> enoughTime = [&] (ll totalTime) -> bool
        {
            ll currTrips = 0;
            
            for(int currTime : time)
                currTrips += totalTime / currTime;
            
            return currTrips >= totalTrips;
        };
        
        ll low = 1, high = (ll) *max_element(time.begin(), time.end()) * totalTrips;
        
        while(low < high)
        {
            ll mid = low + (high - low) / 2;
            
            if(enoughTime(mid))
                high = mid;
            
            else
                low = mid + 1;
        }
        
        return low;
    }
};