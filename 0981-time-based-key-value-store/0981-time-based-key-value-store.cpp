class TimeMap {
private:
    map<string, pair<vector<int>, map<int, string>>> mp; // {key, {timestamps, {timestamp, value}}}.
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].first.push_back(timestamp);
        mp[key].second[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end() or
           timestamp < mp[key].first[0])
            return "";
        
        auto &[allTimes, allValues] = mp[key];
        
        int low = 0, high = allTimes.size() - 1;
        
        while(low < high)
        {
            int mid = (low + high + 1) / 2;
            
            if(allTimes[mid] > timestamp)
                high = mid - 1;
            
            else
                low = mid;
        }
        
        return allValues[allTimes[high]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */