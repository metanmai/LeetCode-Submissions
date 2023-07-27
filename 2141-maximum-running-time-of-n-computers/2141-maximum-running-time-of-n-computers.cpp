#define ll long long

class Solution {
public:
    ll maxRunTime(int n, vector<int>& batteries) {
        ll low = 0, high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
        
        auto canRun = [&] (ll minutes) -> bool
        {
            ll totalPower = 0;
            
            for (ll power : batteries)
                totalPower += min(power, minutes);

            return totalPower >= (ll) n * minutes;
        };
        
        while(low < high)
        {
            ll mid = (high + low + 1) / 2;
            
            if(canRun(mid))
                low = mid;
            
            else
                high = mid - 1;
        }
        
        return low;
    }
};