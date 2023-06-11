class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> allTrips, inCar;
        
        for(auto trip : trips)
            allTrips.push({trip[1], trip[2], trip[0]}); // {from, to, capacity};
        
        int seats = 0;
        int currLoc = 0;
        
        while(!allTrips.empty())
        {
            auto curr = allTrips.top(); allTrips.pop();
            currLoc = curr[0];
            
            while(inCar.size() > 0 and inCar.top()[0] <= currLoc)
            {
                seats -= inCar.top()[1]; inCar.pop();
            }
            
            seats += curr[2];
            inCar.push({curr[1], curr[2]});
            
            if(seats > capacity)
                return false;
        }
        
        return true;
    }
};