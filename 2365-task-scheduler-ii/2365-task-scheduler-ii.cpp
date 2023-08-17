#define ll long long

class Solution {
public:
    ll taskSchedulerII(vector<int>& tasks, int space) {
        map<int, ll> completionDay;
        ll currDay = 0;
        
        for(int task : tasks)
        {
            currDay++;
            
            if(completionDay[task] > currDay)
                currDay = completionDay[task];
            
            completionDay[task] = currDay + space + 1;
        }
        
        return currDay;
    }
};