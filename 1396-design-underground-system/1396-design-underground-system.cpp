class UndergroundSystem {
private:
    map<string, map<string, pair<int, int>>> stationTime; // {start : {end : {totalTime, numberOfTimes}}}
    map<int, pair<string, int>> startDetails;
    
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        startDetails[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = startDetails[id];
        
        stationTime[startStation][stationName].first += t - startTime;
        stationTime[startStation][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double) stationTime[startStation][endStation].first / stationTime[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */